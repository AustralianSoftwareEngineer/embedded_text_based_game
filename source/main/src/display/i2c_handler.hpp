#ifndef I2C_HANDLER_H
#define I2C_HANDLER_H

#include <stdint.h>
#include "../../main.hpp"


void WriteToScreen(const bool, unsigned char);
void FillScreen(unsigned char);
void FillScreen(unsigned char, uint8_t, uint8_t);
void PushToScreen(unsigned char*);
void FillScreenAlternating(unsigned char, unsigned char);
void MoveToNextLine(uint8_t);
void MoveCursor(uint8_t, uint8_t);
void DisplaySetupCommands();

#endif