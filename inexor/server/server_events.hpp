/// @file server_events.hpp
/// @brief 
/// @author Johannes Schneider
/// @date 01.Oct.2016

#ifndef INEXOR_SERVER_EVENTS_H_
#define INEXOR_SERVER_EVENTS_H_

#include "inexor/server/server_gameplay.hpp"

namespace inexor {
namespace server {

    /**
    *
    */
    struct clientinfo;

    /**
     *
     */
    struct gameevent
    {
        virtual ~gameevent() {}

        virtual bool flush(clientinfo *ci, int fmillis)
        {
            process(ci);
            return true;
        }
        virtual void process(clientinfo *ci) {}

        virtual bool keepable() const { return false; }
    };

    /**
     *
     */
    struct timedevent : gameevent
    {
        int millis;
        
        bool flush(clientinfo *ci, int fmillis)
        {
            if(millis > fmillis) return false;
            else if(millis >= ci->lastevent)
            {
                ci->lastevent = millis;
                process(ci);
            }
            return true;
        }
    };

    /**
     *
     */
    struct shotevent : timedevent
    {
        int id, gun;
        vec from, to;
        vector<hitinfo> hits;

        void process(clientinfo *ci)
        {
            gamestate &gs = ci->state;
            int wait = millis - gs.lastshot;
            if(gun!=GUN_SPLINTER &&
               (!gs.isalive(gamemillis) ||
               wait<gs.gunwait ||
               gun<GUN_FIST || gun>GUN_BOMB  ||
               gs.ammo[gun]<=0 || (guns[gun].range && from.dist(to) > guns[gun].range + 1)))
                return;
            if(gun!=GUN_FIST) gs.ammo[gun]--;
            gs.lastshot = millis;
            gs.gunwait = guns[gun].attackdelay;
            sendf(-1, 1, "rii9x", N_SHOTFX, ci->clientnum, gun, id,
                  int(from.x*DMF), int(from.y*DMF), int(from.z*DMF),
                  int(to.x*DMF), int(to.y*DMF), int(to.z*DMF),
                  ci->ownernum);
            gs.shotdamage += guns[gun].damage*(gs.quadmillis ? 4 : 1)*guns[gun].rays;
            switch(gun)
            {
                case GUN_RL: gs.rockets.add(id); break;
                case GUN_GL: gs.grenades.add(id); break;
                case GUN_BOMB: gs.bombs.add(id); break;
                default:
                {
                    int totalrays = 0, maxrays = guns[gun].rays;
                    loopv(hits)
                    {
                        hitinfo &h = hits[i];
                        clientinfo *target = getinfo(h.target);
                        if(!target || target->state.state!=CS_ALIVE || h.lifesequence!=target->state.lifesequence || h.rays<1 || h.dist > guns[gun].range + 1) continue;

                        totalrays += h.rays;
                        if(totalrays>maxrays) continue;
                        int damage = h.rays*guns[gun].damage;
                        if(gs.quadmillis) damage *= 4;
                        dodamage(target, ci, damage, gun, h.dir);
                    }
                    break;
                }
            }
        }

    };

    /**
     *
     */
    struct explodeevent : timedevent
    {
        int id, gun;
        vector<hitinfo> hits;

        bool keepable() const
        {
            return true;
        }

        /**
         *
         */
        void process(clientinfo *ci)
        {
            gamestate &gs = ci->state;
            switch(gun)
            {
                case GUN_RL:
                    if(!gs.rockets.remove(id)) return;
                    break;

                case GUN_GL:
                    if(!gs.grenades.remove(id)) return;
                    break;

                case GUN_BOMB:
                    if(!gs.bombs.remove(id)) return;
                    break;

                case GUN_SPLINTER:
                    break;

                default:
                    return;
            }
            sendf(-1, 1, "ri4x", N_EXPLODEFX, ci->clientnum, gun, id, ci->ownernum);
            if(gun==GUN_BOMB && ci->state.ammo[GUN_BOMB] < itemstats[GUN_BOMB].max) ci->state.ammo[GUN_BOMB]++; // add a bomb if the bomb explodes
            loopv(hits)
            {
                hitinfo &h = hits[i];
                clientinfo *target = getinfo(h.target);
                if(!target || target->state.state!=CS_ALIVE || h.lifesequence!=target->state.lifesequence || h.dist<0 || h.dist>guns[gun].exprad) continue;

                bool dup = false;
                loopj(i) if(hits[j].target==h.target) { dup = true; break; }
                if(dup) continue;

                int damage = guns[gun].damage;
                if(gs.quadmillis) damage *= 4;
                damage = int(damage*(1-h.dist/EXP_DISTSCALE/guns[gun].exprad));
                if(target==ci) damage /= EXP_SELFDAMDIV;
                dodamage(target, ci, damage, gun, h.dir);
            }
        }

    };

    /**
     *
     */
    struct suicideevent : gameevent
    {
        void process(clientinfo *ci)
        {
            suicide(ci);
        }
    };

    /**
     *
     */
    struct pickupevent : gameevent
    {
        int ent;

        void process(clientinfo *ci)
        {
            gamestate &gs = ci->state;
            if(m_mp(gamemode) && !gs.isalive(gamemillis)) return;
            pickup(ent, ci->clientnum);
        }

    };


};
};


#endif /* INEXOR_SERVER_EVENTS_H_ */
