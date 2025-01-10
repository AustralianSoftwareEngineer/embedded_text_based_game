#include "combat_scene_handler.h"

//Paused work on this to look at profiling and think of better naming conventions.

CombatScene::DisplayHealth()
{
  // Player
  MoveCursor(0x07, 0x00);
  TextPusherArray("HP: ", 4);
  unsigned char message_player_health = (char)player_health;
  TextPusherArray(message_player_health, 3);

  // Enemy
  MoveCursor(0x07, 0x62);
  unsigned char message_enemy_health = (char)enemy_health;
  TextPusherArray(message_enemy_health, 3);
  TextPusherArray(" :HP", 4);
}