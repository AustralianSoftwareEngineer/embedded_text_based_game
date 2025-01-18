#include "main.hpp"

void setup() {
  Serial.begin(9600);
  Wire.begin();
  delay(1000);
  DisplaySetupCommands();
  FillScreen(0x00);

  // Title Screen:
  MoveCursor(0x00, 0x00);
  const unsigned char message[] = "WELCOME ADVENTURER TO  THE NECROTIC MIRE!";
  I2CTextPusher(message, sizeof(message));


  delay(2000);
  const unsigned char messageLower[] = "Generic Introduction has been Completed";
  I2CDialoguePusher(messageLower, sizeof(messageLower));
  
  delay(3500);

}




void loop() {

  CombatScene player_character;
  player_character.DisplayHealth();
  delay(10000);
  FillScreen(0x00);
  // Replace with HUD needing to be here.
  player_character.DisplayHealth();


  NarrativeStoryTeller(0);
  Serial.println("Passed this");
  for (int i = 0; i < 10; i++)
  {
    NarrativeShopkeeper(i);
    delay(2500);
    player_character.DisplayHealth();
    delay(500);
  }
  delay(1000);
  delay(5000);

  //NarrativeReadFromFlash(shopkeeper_banter_one);

}
