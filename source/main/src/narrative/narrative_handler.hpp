#ifndef NARRATIVE_HANDLER_H
#define NARRATIVE_HANDLER_H

#include <avr/pgmspace.h>
#include "../../main.hpp"
#include "./enemies.hpp"
#include "./shopkeeper.hpp"
#include "./storyteller.hpp"

enum NonPlayerableCharacterDialogue {
    kStoryteller = 0,
    kShopkeeper = 1,
    kEnemies = 2
};


void NarrativeReadFromFlash(uint16_t, NonPlayerableCharacterDialogue);
void NarrativeStoryTeller(uint16_t);
void NarrativeShopkeeper(uint16_t);

#endif