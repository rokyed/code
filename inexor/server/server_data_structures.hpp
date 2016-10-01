/// @file server_data_structures.hpp
/// @brief This file contains all structures and classes related to the game server
/// @author Johannes Schneider
/// @date 91.Oct.2016

#ifndef INEXOR_SERVER_DATA_STRUCTURES_H_
#define INEXOR_SERVER_DATA_STRUCTURES_H_

#include "inexor/fpsgame/game.hpp"

namespace inexor {
namespace server {

    static const int DEATHMILLIS = 300;


    /**
     * server side version of "entity" type
     */
    struct server_entity
    {
        int type;
        int spawntime;
        bool spawned;
    };

    /**
     *
     */
    struct hitinfo
    {
        int target;
        int lifesequence;
        int rays;
        float dist;
        vec dir;
    };

    /**
     *
     */
    template <int N>
    struct projectilestate
    {
        int projs[N];
        int numprojs;

        projectilestate() : numprojs(0) {}

        void reset() { numprojs = 0; }

        void add(int val)
        {
            if(numprojs>=N) numprojs = 0;
            projs[numprojs++] = val;
        }

        bool remove(int val)
        {
            loopi(numprojs) if(projs[i]==val)
            {
                projs[i] = projs[--numprojs];
                return true;
            }
            return false;
        }
    };

    /**
     *
     */
    struct ban
    {
        int time, expire;
        uint ip;
    };

    /**
     *
     */
    struct demofile
    {
        string info;
        uchar *data;
        int len;
    };
    
    /**
     *
     */
    struct teamkillkick
    {
        int modes, limit, ban;

        bool match(int mode) const
        {
            return (modes&(1<<(mode-STARTGAMEMODE)))!=0;
        }

        bool includes(const teamkillkick &tk) const
        {
            return tk.modes != modes && (tk.modes & modes) == tk.modes;
        }
    };

    /**
     *
     */
    struct teamkillinfo
    {
        uint ip;
        int teamkills;
    };

    /**
     *
     */
    struct teamrank
    {
        const char *name;
        float rank;
        int clients;

        teamrank(const char *name) : name(name), rank(0), clients(0) {}
    };

    /*
     * MSG filter works as a firewall
     * it allowes only certain messages for certain things, see checktype
     * -1 will become 1 in the switchcase below, its a hack to not 
     * misinterpretate the different cases as messages 
     */
    static struct msgfilter
    {
        uchar msgmask[NUMMSG];

        msgfilter(int msg, ...)
        {
            memset(msgmask, 0, sizeof(msgmask));
            va_list msgs;
            va_start(msgs, msg);
            for(uchar val = 1; msg < NUMMSG; msg = va_arg(msgs, int))
            {
                if(msg < 0) val = uchar(-msg);
                else msgmask[msg] = val;
            }
            va_end(msgs);
        }

        uchar operator[](int msg) const { return msg >= 0 && msg < NUMMSG ? msgmask[msg] : 0; }
    } msgfilter(-1, N_CONNECT, N_SERVINFO, N_INITCLIENT, N_WELCOME, N_MAPCHANGE, N_SERVMSG, N_DAMAGE, N_HITPUSH, N_SHOTFX, N_EXPLODEFX, N_DIED, N_SPAWNSTATE, N_FORCEDEATH, N_TEAMINFO, N_ITEMACC, N_ITEMSPAWN, N_TIMEUP, N_CDIS, N_CURRENTMASTER, N_PONG, N_RESUME, N_BASESCORE, N_BASEINFO, N_BASEREGEN, N_ANNOUNCE, N_SENDDEMOLIST, N_SENDDEMO, N_DEMOPLAYBACK, N_SENDMAP, N_DROPFLAG, N_SCOREFLAG, N_RETURNFLAG, N_RESETFLAG, N_INVISFLAG, N_CLIENT, N_AUTHCHAL, N_INITAI, N_EXPIRETOKENS, N_DROPTOKENS, N_STEALTOKENS, N_DEMOPACKET,
                -2, N_REMIP, N_NEWMAP, N_GETMAP, N_SENDMAP, N_CLIPBOARD,
                -3, N_EDITENT, N_EDITF, N_EDITT, N_EDITM, N_FLIP, N_COPY, N_PASTE, N_ROTATE, N_REPLACE, N_DELCUBE, N_EDITVAR, N_EDITVSLOT, N_UNDO, N_REDO,
                -4, N_POS, NUMMSG),
        connectfilter(-1, N_CONNECT, -2, N_AUTHANS, -3, N_PING, NUMMSG);


    /**
     *
     */
    struct worldstate
    {
        int uses, len;
        uchar *data;

        worldstate() : uses(0), len(0), data(NULL) {}

        void setup(int n) { len = n; data = new uchar[n]; }
        void cleanup() { DELETEA(data); len = 0; }
        bool contains(const uchar *p) const { return p >= data && p < &data[len]; }
    };

    /**
     *
     */
    struct crcinfo
    {
        int crc, matches;

        crcinfo() {}
        crcinfo(int crc, int matches) : crc(crc), matches(matches) {}

        static bool compare(const crcinfo &x, const crcinfo &y) { return x.matches > y.matches; }
    };


};
};

#endif /* INEXOR_SERVER_DATA_STRUCTURES_H_ */
