/// 
/// 
/// 
/// 

#ifndef INEXOR_SERVER_ASSETS_H_
#define INEXOR_SERVER_ASSETS_H_

#include "inexor/server/server_data_structures.hpp"

namespace inexor {
namespace server {

    ///
    ///
    ///
    static bool searchmodename(const char *haystack, const char *needle)
    {
        if(!needle[0]) return true;
        do
        {
            if(needle[0] != '.')
            {
                haystack = strchr(haystack, needle[0]);
                if(!haystack) break;
                haystack++;
            }
            const char *h = haystack, *n = needle+1;
            for(; *h && *n; h++)
            {
                if(*h == *n) n++;
                else if(*h != ' ') break; 
            }
            if(!*n) return true;
            if(*n == '.') return !*h;
        } while(needle[0] != '.');
        return false;
    }

    ///
    ///
    ///
    static int genmodemask(vector<char *> &modes)
    {
        long modemask = 0;
        loopv(modes)
        {
            const char *mode = modes[i];
            int op = mode[0];
            switch(mode[0])
            {
                case '*':
                    modemask |= (long)1<<NUMGAMEMODES;
                    loopk(NUMGAMEMODES) if(m_checknot(k+STARTGAMEMODE, M_DEMO|M_EDIT|M_LOCAL)) modemask |= 1<<k;
                    continue;
                case '!':
                    mode++;
                    if(mode[0] != '?') break;
                case '?':
                    mode++;
                    loopk(NUMGAMEMODES) if(searchmodename(gamemodes[k].name, mode))
                    {
                        if(op == '!') modemask &= ~(1<<k);
                        else modemask |= 1<<k;
                    }
                    continue;
            }
            int modenum = INT_MAX;
            if(isdigit(mode[0])) modenum = atoi(mode);
            else loopk(NUMGAMEMODES) if(searchmodename(gamemodes[k].name, mode)) { modenum = k+STARTGAMEMODE; break; }
            if(!m_valid(modenum)) continue;
            switch(op)
            {
                case '!': modemask &= ~(1 << (modenum - STARTGAMEMODE)); break;
                default: modemask |= 1 << (modenum - STARTGAMEMODE); break;
            }
        }
        return modemask;
    }


    /// 
    /// 
    /// 
    static const char *privname(int type)
    {
        switch(type)
        {
            case PRIV_ADMIN: return "admin";
            case PRIV_AUTH: return "auth";
            case PRIV_MASTER: return "master";
            default: return "unknown";
        }
    }

    /// 
    /// 
    /// 
    static int msgsizelookup(int msg)
    {
        static int sizetable[NUMMSG] = { -1 };
        if(sizetable[0] < 0)
        {
            memset(sizetable, -1, sizeof(sizetable));
            for(const int *p = msgsizes; *p >= 0; p += 2) sizetable[p[0]] = p[1];
        }
        return msg >= 0 && msg < NUMMSG ? sizetable[msg] : -1;
    }

    /// 
    /// 
    /// 
    static const char *modename(int n, const char *unknown)
    {
        if(m_valid(n)) return gamemodes[n - STARTGAMEMODE].name;
        return unknown;
    }

    /// 
    /// 
    /// 
    static const char *mastermodename(int n, const char *unknown)
    {
        return (n>=MM_START && size_t(n-MM_START)<sizeof(mastermodenames)/sizeof(mastermodenames[0])) ? mastermodenames[n-MM_START] : unknown;
    }


    /// 
    /// 
    /// 
    static bool duplicatename(clientinfo *ci, const char *name)
    {
        if(!name) name = ci->name;
        loopv(clients) if(clients[i]!=ci && !strcmp(name, clients[i]->name)) return true;
        return false;
    }

    /// 
    /// 
    /// 
    static const char *colorname(clientinfo *ci, const char *name = NULL)
    {
        if(!name) name = ci->name;
        if(name[0] && !duplicatename(ci, name) && ci->state.aitype == AI_NONE) return name;
        static string cname[3];
        static int cidx = 0;
        cidx = (cidx+1)%3;
        formatstring(cname[cidx], ci->state.aitype == AI_NONE ? "%s %s(%d)%s" : "%s %s[%d]%s", name, COL_MAGENTA, ci->clientnum, COL_WHITE);
        return cname[cidx];
    }

    /// 
    /// 
    /// 
    static int scaletime(int t)
    {
        return t*gamespeed;
    }

    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


    /// 
    /// 
    /// 


};
};

#endif // INEXOR_SERVER_ASSETS_H_