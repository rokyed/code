/// @file server_data_structures.hpp
/// @brief This file contains all structures and classes related to the game server
/// @author Johannes Schneider
/// @date 91.Oct.2016

#ifndef INEXOR_SERVER_DATA_STRUCTURES_H_
#define INEXOR_SERVER_DATA_STRUCTURES_H_

#include "inexor/fpsgame/game.hpp"

namespace inexor {
namespace server {

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

}
}

#endif /* INEXOR_SERVER_DATA_STRUCTURES_H_ */
