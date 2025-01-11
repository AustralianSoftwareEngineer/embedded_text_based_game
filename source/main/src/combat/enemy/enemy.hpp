#ifndef ENEMY_H
#define ENEMY_H

#include "../../../main.hpp"
#include "../combat_handler.hpp"

class enemy
{
public:
    uint8_t enemy_health[4];
    uint8_t enemy_attack;
    uint8_t enemy_defence;
    unsigned char* enemy_name[];
    //CombatActions attack_pattern[];
};

#endif