#include "main.h"

void setup() {
  Serial.begin(9600);
  Wire.begin();
  delay(1000);
  DisplaySetupCommands();
  MoveCursor(0x00, 0x00);
  FillScreen(0x00);
}

void loop() {

  //MoveCursor(0x00, 0x00);
  //FillScreen(0xA5);

/* Proof of concept / able to expect correct display  
  MoveCursor(0x00, 0x00);
  PushToScreen(0x1E);
  PushToScreen(0x05);
  PushToScreen(0x05);
  PushToScreen(0x05);
  PushToScreen(0x1E);
  MoveCursor(0x01, 0x00);
  PushToScreen(B00011110);
  PushToScreen(B00000101);
  PushToScreen(B00000101);
  PushToScreen(B00000101);
  PushToScreen(B00011110); */

  delay(1000);
  MoveCursor(0x00, 0x00);
  unsigned char message[] = "HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO HELLO ";
  TextPusher(message, sizeof(message));  
}
