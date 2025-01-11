#ifndef PLAYER_H
#define PLAYER_H

#include "../../../main.hpp"

class player
{
public:
    uint8_t player_health[4];
    uint8_t player_attack;
    uint8_t player_defence;
    unsigned char* player_name[];
};

#endif