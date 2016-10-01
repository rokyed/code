/// @file server_data_structures.hpp
/// @brief This file contains all structures and classes related to the game server
/// @author Johannes Schneider
/// @date 91.Oct.2016

#ifndef INEXOR_SERVER_DATA_STRUCTURES_H_
#define INEXOR_SERVER_DATA_STRUCTURES_H_

namespace inexor {
namespace server {

    struct server_entity            // server side version of "entity" type
    {
        int type;
        int spawntime;
        bool spawned;
    };

}
}

#endif /* INEXOR_SERVER_DATA_STRUCTURES_H_ */
