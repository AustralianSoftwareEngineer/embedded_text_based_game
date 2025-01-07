#include "main.h"

void setup() {
  Serial.begin(9600);
  Wire.begin();
  delay(1000);
  DisplaySetupCommands();
}

void loop() {

  MoveCursor(0x00, 0x00);
  FillScreen(0xA5);

  MoveCursor(0x00, 0x00);
  FillScreen(0x00);

}
