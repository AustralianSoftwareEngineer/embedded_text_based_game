#ifndef COMBAT_HANDLER_H
#define COMBAT_HANDLER_H

#include "../../main.hpp"

enum class CombatActions {
    kAttack = 0,
    kDefend = 1,
    kSkip = 2,
    kItem = 3,
};

void AttackPatternResolver(CombatActions*[]);

#endif