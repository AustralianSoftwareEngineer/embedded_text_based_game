#ifndef COMBAT_SCENE_HANDLER_H
#define COMBAT_SCENE_HANDLER_H

#include "./main.h"

//Paused work on this to look at profiling and think of better naming conventions.

class CombatScene {

public:

  unsigned char player_health[4] = {'5','2','8','7'};
  unsigned char enemy_health[4] = {'0','6','1','2'}; 
  //unsigned char 


  CombatScene() {
  }

  void DisplayHealth();
  uint8_t HealthDamageHandler(unsigned char[],unsigned char[]);
//private:

};

#endif