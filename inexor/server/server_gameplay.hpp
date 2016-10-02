/// @file server_gameplay.hpp
/// @brief 
/// @author Johannes Schneider
/// @date 01.Oct.2016

#ifndef INEXOR_SERVER_GAMEPLAY_H_
#define INEXOR_SERVER_GAMEPLAY_H_

#include "inexor/fpsgame/game.hpp"
#include "inexor/server/server_data_structures.hpp"

namespace inexor {
namespace server {

    /**
     *
     */
    static int numclients(int exclude = -1, bool nospec = true, bool noai = true, bool priv = false)
    {
        int n = 0;
        loopv(clients) 
        {
            clientinfo *ci = clients[i];
            if(ci->clientnum!=exclude && (!nospec || ci->state.state!=CS_SPECTATOR || (priv && (ci->privilege || ci->local))) && (!noai || ci->state.aitype == AI_NONE)) n++;
        }
        return n;
    }

    /**
     *
     */
    static int spawntime(int type)
    {
        if(m_classicsp) return INT_MAX;
        int np = numclients(-1, true, false);
        np = np<3 ? 4 : (np>4 ? 2 : 3);         // spawn times are dependent on number of players
        int sec = 0;
        switch(type)
        {
            case I_SHELLS:
            case I_BULLETS:
            case I_ROCKETS:
            case I_ROUNDS:
            case I_GRENADES:
            case I_CARTRIDGES: sec = np*4; break;
            case I_BOMBS:
            case I_BOMBRADIUS: sec = np*9; break;
            case I_BOMBDELAY: sec = np*7; break;
            case I_HEALTH: sec = np*5; break;
            case I_GREENARMOUR: sec = 20; break;
            case I_YELLOWARMOUR: sec = 30; break;
            case I_BOOST: sec = 60; break;
            case I_QUAD: sec = 70; break;
        }
        return sec*1000;
    }

    // pre declaration
    static clientinfo *getinfo(int n);

    /**
     *
     */
    static bool pickup(int i, int sender)
    {
        if((m_timed && gamemillis>=gamelimit) || !sents.inrange(i) || !sents[i].spawned) return false;
        clientinfo *ci = getinfo(sender);
        if(!ci || (!ci->local && !ci->state.canpickup(sents[i].type))) return false;
        sents[i].spawned = false;
        sents[i].spawntime = spawntime(sents[i].type);
        sendf(-1, 1, "ri3", N_ITEMACC, i, sender);
        ci->state.pickup(sents[i].type);
        return true;
    }

    /**
     *
     */
    static void changegamespeed(int val, clientinfo *ci = NULL)
    {
        val = clamp(val, 10, 1000);
        if(inexor::server::gamespeed==val) return;
        inexor::server::gamespeed = val;
        sendf(-1, 1, "riii", N_GAMESPEED, inexor::server::gamespeed, ci ? ci->clientnum : -1);
    }

    /**
     *
     */
    static void checkintermission()
    {
        if(gamemillis >= gamelimit && !interm && !m_timeforward)
        {
            sendf(-1, 1, "ri2", N_TIMEUP, 0);
            if(smode) smode->intermission();
            changegamespeed(100);
            interm = gamemillis + 10000;
        }
    }

    /**
     *
     */
    static void startintermission()
    {
        gamelimit = min(gamelimit, gamemillis);
        checkintermission();
    }

    /**
     *
     */
    static void forceintermission()
    {
        if(interm) return;
        interm = gamemillis + 10000;
        sendf(-1, 1, "ri2", N_TIMEUP, 0);
        if(smode) smode->intermission();
    }


    /**
     * Checks if the game has ended because only 
     * one player is still alive. It does this by 
     * checking if less than 2 players have their state set to alive.
     * This means, the game will also end if someone is gagging
     * If only one is still alive this method forces intermission.
     */
    static void checklms()
    {
        if(m_teammode)
        {
            int teamsalive = 0;
            vector<teamscore> teams;
            for(int cn=0; cn<clients.length(); cn++)
            {
                bool found = false;
                for(int t=0; t<teams.length(); t++)
                {
                    if(strcmp(teams[t].team, clients[cn]->team) == 0)
                    {
                        found = true;
                        if(clients[cn]->state.state == CS_ALIVE) teams[t].score++;
                        break;
                    }
                }
                if(!found) teams.add(teamscore(clients[cn]->team, (clients[cn]->state.state == CS_ALIVE) ? 1 : 0));
            }
            for(int t=0; t<teams.length(); t++)
            {
                if(teams[t].score > 0) teamsalive++;
            }
            if(teamsalive < 2) startintermission();
        }
        else
        {
            int plalive = 0;  // Number of players still alive;
                              // n > 1 Means the game is still running;
                              // 1 means player x has won;
                              // n < 1 means that the game should end, but there is now winner (probatly only,
                              // if the two last players killed them self at the same time)
            int clfound = -1; // The index of the client whose player is last found as alive, the winner. IF $plalive == 1
                              // It is currently not used
                              // Get player check if players are alive; if yes set plfound and increase plalive
            for (int clnum = 0; clnum < clients.length() && plalive < 2; clnum++)
                if (clients[clnum]->state.state == CS_ALIVE) {
                    plalive++;
                    clfound = clnum;
                }
            // Stop game if less than 2 players are alive
            if (plalive < 2) startintermission();
        }
    }

    /**
     *
     */
    static void addteamkill(clientinfo *actor, clientinfo *victim, int n)
    {
        if(!m_timed || actor->state.aitype != AI_NONE || actor->local || actor->privilege || (victim && victim->state.aitype != AI_NONE)) return;
        shouldcheckteamkills = true;
        uint ip = getclientip(actor->clientnum);
        loopv(teamkills) if(teamkills[i].ip == ip) 
        { 
            teamkills[i].teamkills += n;
            return;
        }
        teamkillinfo &tk = teamkills.add();
        tk.ip = ip;
        tk.teamkills = n;
    }

    /**
     *
     */
    static clientinfo *getinfo(int n)
    {
        if(n < MAXCLIENTS) return (clientinfo *)getclientinfo(n);
        n -= MAXCLIENTS;
        return bots.inrange(n) ? bots[n] : NULL;
    }

    /**
     *
     */
    static void suicide(clientinfo *ci)
    {
        gamestate &gs = ci->state;
        if(gs.state!=CS_ALIVE) return;
        int fragvalue = smode ? smode->fragvalue(ci, ci) : -1;
        ci->state.frags += fragvalue;
        ci->state.deaths++;
        teaminfo *t = m_teammode ? teaminfos.access(ci->team) : NULL;
        if(t) t->frags += fragvalue;
        sendf(-1, 1, "ri5", N_DIED, ci->clientnum, ci->clientnum, gs.frags, t ? t->frags : 0);
        ci->position.setsize(0);
        if(smode) smode->died(ci, NULL);
        gs.state = CS_DEAD;
        gs.lastdeath = gamemillis;
        gs.respawn();
        if (m_lms) checklms();
    }


    /**
     *
     */
    static void dodamage(clientinfo *target, clientinfo *actor, int damage, int gun, const vec &hitpush = vec(0, 0, 0))
    {
        if (smode && !smode->canhit(target, actor)) return;
        gamestate &ts = target->state;
        ts.dodamage(damage);
        if(target!=actor && !isteam(target->team, actor->team)) actor->state.damage += damage;
        sendf(-1, 1, "ri6", N_DAMAGE, target->clientnum, actor->clientnum, damage, ts.armour, ts.health);
        if(target==actor) target->setpushed();
        else if(!hitpush.iszero())
        {
            ivec v(vec(hitpush).rescale(DNF));
            sendf(ts.health<=0 ? -1 : target->ownernum, 1, "ri7", N_HITPUSH, target->clientnum, gun, damage, v.x, v.y, v.z);
            target->setpushed();
        }
        if(ts.health<=0)
        {
            target->state.deaths++;
            int fragvalue = smode ? smode->fragvalue(target, actor) : (target==actor || isteam(target->team, actor->team) ? -1 : 1);
            actor->state.frags += fragvalue;
            if(fragvalue>0)
            {
                int friends = 0, enemies = 0; // note: friends also includes the fragger
                if(m_teammode) loopv(clients) if(strcmp(clients[i]->team, actor->team)) enemies++; else friends++;
                else { friends = 1; enemies = clients.length()-1; }
                actor->state.effectiveness += fragvalue*friends/float(max(enemies, 1));
            }
            teaminfo *t = m_teammode ? teaminfos.access(actor->team) : NULL;
            if(t) t->frags += fragvalue; 
            sendf(-1, 1, "ri5", N_DIED, target->clientnum, actor->clientnum, actor->state.frags, t ? t->frags : 0);
            target->position.setsize(0);
            if(smode) smode->died(target, actor);
            ts.state = CS_DEAD;
            ts.lastdeath = gamemillis;

            if (m_lms) checklms(); // Last Man Standing
            else ts.respawn();

            if(actor!=target && isteam(actor->team, target->team)) 
            {
                actor->state.teamkills++;
                addteamkill(actor, target, 1);
            }

            ts.deadflush = ts.lastdeath + DEATHMILLIS;
            // don't issue respawn yet until DEATHMILLIS has elapsed
            // ts.respawn();
        }
    }



};
};

#endif /* INEXOR_SERVER_GAMEPLAY_H_ */
