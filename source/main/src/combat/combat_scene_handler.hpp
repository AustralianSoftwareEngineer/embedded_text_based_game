#ifndef COMBAT_SCENE_HANDLER_H
#define COMBAT_SCENE_HANDLER_H

#include "../../main.hpp"

//Paused work on this to look at profiling and think of better naming conventions.

class CombatScene {

public:

  unsigned char player_health[4] = {'0','1','0','8'};
  unsigned char enemy_health[4] = {'0','0','2','5'}; 
  //unsigned char 


  CombatScene() {
  }

  ~CombatScene() {
    
  }

  void DisplayHealth();
  uint8_t HealthDamageHandler(unsigned char[],unsigned char[]);
//private:

};

#endif