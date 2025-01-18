#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include "../../main.hpp"

void I2CDialoguePusher(const unsigned char*, uint8_t);
void I2CTextPusher(const unsigned char*, uint8_t);
unsigned char I2CTextVerification(unsigned char);
void I2CDialogueFromFlashPusher(unsigned char);
//void TextPusher(unsigned char*, uint8_t);
//void TextPusherNumberHandler(char[]);

#endif