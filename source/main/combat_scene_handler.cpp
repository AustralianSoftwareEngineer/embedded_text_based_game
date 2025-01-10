#include "combat_scene_handler.h"

//Paused work on this to look at profiling and think of better naming conventions.

void CombatScene::DisplayHealth()
{
  // Player
  MoveCursor(0x06, 0x00);
  unsigned char player_name[8] = {"Rod"};
  TextPusherArray(player_name, sizeof(player_name));
  MoveCursor(0x07, 0x00);
  TextPusherArray("HP: ", 4);
  TextPusherArray(player_health,4);

  // Enemy
  MoveCursor(0x06, 0x50);
  unsigned char enemy_name[3] = {"GGG"};
  TextPusherArray(enemy_name, sizeof(enemy_name));
  MoveCursor(0x07, 0x50);
  TextPusherArray(enemy_health,4);
  TextPusherArray(" :HP", 4);
}


// Completely unused at the moment.
//0 = 48 && 9 = 57
uint8_t CombatScene::HealthDamageHandler(unsigned char health[], unsigned char modifier[])
{
  if (modifier[0] > health[0])
  {
    uint8_t overkill[4] = {0,0,0,0};
    return overkill;
  }
  for (uint8_t i = 0; i < 4; i++)
  {
    if (health[i] < modifier[i] && i != 0)
    {
      health[i+1] -= 1;
      health[i] += 10 - modifier[i];
    }
    else 
    {
      health[i] -= modifier[i];
    }
  }
  uint8_t result = health;
  return health;
}