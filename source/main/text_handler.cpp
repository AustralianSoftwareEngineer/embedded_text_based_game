#include "text_handler.h"

//I would've used an unordered map and just pulled from there instead but I'm very limited on resources.

const char ktext_in_bytes[][6] = {
    {0x1E, 0x05, 0x05, 0x05, 0x1E, 0x00}, // A 0
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00}, // B 1
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00}, // C 2
    {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00}, // D 3
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00}, // E 4
    {0x1F, 0x10, 0x08, 0x04, 0x1F, 0x00}, // F 5
    {0x1F, 0x11, 0x11, 0x11, 0x1F, 0x00}, // G 6
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00}, // H 7
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00}, // I 8
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00}, // J 9
    {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00}, // K 10
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00}, // L 11
    {0x1F, 0x10, 0x08, 0x04, 0x1F, 0x00}, // M 12
    {0x1F, 0x04, 0x08, 0x10, 0x1F, 0x00}, // N 13
    {0x1F, 0x11, 0x11, 0x11, 0x1F, 0x00}, // O 14
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00}, // P 15
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00}, // Q 16
    {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00}, // R 17
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00}, // S 18
    {0x1F, 0x10, 0x08, 0x04, 0x1F, 0x00}, // T 19
    {0x1F, 0x10, 0x10, 0x10, 0x1F, 0x00}, // U 20
    {0x1E, 0x05, 0x05, 0x05, 0x1E, 0x00}, // V 21
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00}, // W 22
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00}, // X 23
    {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00}, // Y 24
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00}, // Z 25
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  //' '26
};

void TextPusher(unsigned char *message, uint8_t size_of_message)
{
  for (uint8_t i = 0; i < size_of_message; i++)
  {
    unsigned char data = message[i];
    switch (data) {
        case 'A':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'B':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'C':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'D':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'E':
            PushToScreen(ktext_in_bytes[4]);
            break; 
        case 'F':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'G':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'H':
            PushToScreen(ktext_in_bytes[7]);
            break; 
        case 'I':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'J':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'K':
            PushToScreen(ktext_in_bytes[10]);
            break; 
        case 'L':
            PushToScreen(ktext_in_bytes[11]);
            break; 
        case 'M':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'N':
            PushToScreen(ktext_in_bytes[13]);
            break; 
        case 'O':
            PushToScreen(ktext_in_bytes[14]);
            break; 
        case 'P':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'Q':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'R':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'S':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'T':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'U':
            PushToScreen(ktext_in_bytes[20]);
            break; 
        case 'V':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'W':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'X':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'Y':
            PushToScreen(ktext_in_bytes[0]);
            break; 
        case 'Z':
            PushToScreen(ktext_in_bytes[0]);
            break;
        case ' ':
            PushToScreen(ktext_in_bytes[26]);
        default:
            break;
    }
  }
}



