#include "main.h"

void setup() {
  Serial.begin(9600);
  Wire.begin();
  delay(1000);
  DisplaySetupCommands();
  FillScreen(0x00);

  MoveCursor(0x00, 0x00);
  const unsigned char message[] = "WELCOME ADVENTURER TO  THE NECROTIC MIRE!";
  TextPusherArray(message, sizeof(message)); 
}

void loop() {

  CombatScene player_character;
  player_character.DisplayHealth();
  delay(5000);
}
