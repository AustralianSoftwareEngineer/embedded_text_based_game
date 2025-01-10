#ifndef COMBAT_SCENE_HANDLER_H
#define COMBAT_SCENE_HANDLER_H

#include "./main.h"

//Paused work on this to look at profiling and think of better naming conventions.

class CombatScene {

public:
  int player_health;
  int enemy_health;

  CombatScene() {
    player_health = 1;
    enemy_health = 1; 
  }

  DisplayHealth();
//private:

};

#endif