#include "text_handler.h"

//I would've used an unordered map and just pulled from there instead but I'm very limited on resources.


const PROGMEM char ktext_in_bytes_array[][7] = {
    {0x1E, 0x05, 0x05, 0x05, 0x1E, 0x00, 'A'}, // A 0
    {0x1F, 0x15, 0x15, 0x16, 0x1C, 0x00, 'B'}, // B 1
    {0x1F, 0x11, 0x11, 0x11, 0x11, 0x00, 'C'}, // C 2
    {0x1F, 0x11, 0x11, 0x11, 0x0E, 0x00, 'D'}, // D 3
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00, 'E'}, // E 4
    {0x1F, 0x10, 0x08, 0x04, 0x1F, 0x00, 'F'}, // F 5
    {0x1F, 0x11, 0x11, 0x11, 0x1F, 0x00, 'G'}, // G 6
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00, 'H'}, // H 7
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00, 'I'}, // I 8
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00, 'J'}, // J 9
    {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00, 'K'}, // K 10
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00, 'L'}, // L 11
    {0x1F, 0x10, 0x08, 0x04, 0x1F, 0x00, 'M'}, // M 12
    {0x1F, 0x04, 0x08, 0x10, 0x1F, 0x00, 'N'}, // N 13
    {0x1F, 0x11, 0x11, 0x11, 0x1F, 0x00, 'O'}, // O 14
    {0x1F, 0x05, 0x05, 0x05, 0x07, 0x00, 'P'}, // P 15
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00, 'Q'}, // Q 16
    {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00, 'R'}, // R 17
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00, 'S'}, // S 18
    {0x1F, 0x10, 0x08, 0x04, 0x1F, 0x00, 'T'}, // T 19
    {0x1F, 0x10, 0x10, 0x10, 0x1F, 0x00, 'U'}, // U 20
    {0x1E, 0x05, 0x05, 0x05, 0x1E, 0x00, 'V'}, // V 21
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00, 'W'}, // W 22
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00, 'X'}, // X 23
    {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00, 'Y'}, // Y 24
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00, 'Z'}, // Z 25
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, ' '}, //' '26
 
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00, '0'}, // 0 27
    {0x10, 0x12, 0x1F, 0x10, 0x10, 0x00, '1'}, // 1 28
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00, '2'}, // 2 29
    {0x1F, 0x10, 0x08, 0x04, 0x1F, 0x00, '3'}, // 3 30
    {0x1F, 0x10, 0x10, 0x10, 0x1F, 0x00, '4'}, // 4 31
    {0x1E, 0x05, 0x05, 0x05, 0x1E, 0x00, '5'}, // 5 32
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00, '6'}, // 6 33
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00, '7'}, // 7 34
    {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00, '8'}, // 8 35
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00, '9'}, // 9 36
    {0x00, 0x0A, 0x0A, 0x0A, 0x00, 0x00, ':'}, // : 37
    {0x00, 0x17, 0x17, 0x17, 0x00, 0x00, '!'}, // ! 38
};

const void TextPusherArray(unsigned char *message, uint8_t size_of_message)
{
    for (uint8_t i = 0; i < size_of_message; i++)
    {
        for (uint8_t j = 0; j < 39; j++)
        {
            if (message[i] == ktext_in_bytes_array[j])
            {
                PushToScreen(ktext_in_bytes_array[j]);
            }
        }
    }
}

/*
This gets removed after next push as array is significantly more performant by a minimum factor of 13x and maximum of 41x.

const PROGMEM char ktext_in_bytes[][6] = {
    {0x1E, 0x05, 0x05, 0x05, 0x1E, 0x00}, // A 0
    {0x1F, 0x15, 0x15, 0x16, 0x1C, 0x00}, // B 1
    {0x1F, 0x11, 0x11, 0x11, 0x11, 0x00}, // C 2
    {0x1F, 0x11, 0x11, 0x11, 0x0E, 0x00}, // D 3
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
    {0x1F, 0x05, 0x05, 0x05, 0x07, 0x00}, // P 15
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
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //' '26

    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00}, // 0 27
    {0x10, 0x12, 0x1F, 0x10, 0x10, 0x00}, // 1 28
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00}, // 2 29
    {0x1F, 0x10, 0x08, 0x04, 0x1F, 0x00}, // 3 30
    {0x1F, 0x10, 0x10, 0x10, 0x1F, 0x00}, // 4 31
    {0x1E, 0x05, 0x05, 0x05, 0x1E, 0x00}, // 5 32
    {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00}, // 6 33
    {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00}, // 7 34
    {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00}, // 8 35
    {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00}, // 9 36
    {0x00, 0x0A, 0x0A, 0x0A, 0x00, 0x00}, // : 37
    {0x00, 0x17, 0x17, 0x17, 0x00, 0x00}, // ! 38

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
            PushToScreen(ktext_in_bytes[1]);
            break; 
        case 'C':
            PushToScreen(ktext_in_bytes[2]);
            break; 
        case 'D':
            PushToScreen(ktext_in_bytes[3]);
            break; 
        case 'E':
            PushToScreen(ktext_in_bytes[4]);
            break; 
        case 'F':
            PushToScreen(ktext_in_bytes[5]);
            break; 
        case 'G':
            PushToScreen(ktext_in_bytes[6]);
            break; 
        case 'H':
            PushToScreen(ktext_in_bytes[7]);
            break; 
        case 'I':
            PushToScreen(ktext_in_bytes[8]);
            break; 
        case 'J':
            PushToScreen(ktext_in_bytes[9]);
            break; 
        case 'K':
            PushToScreen(ktext_in_bytes[10]);
            break; 
        case 'L':
            PushToScreen(ktext_in_bytes[11]);
            break; 
        case 'M':
            PushToScreen(ktext_in_bytes[12]);
            break; 
        case 'N':
            PushToScreen(ktext_in_bytes[13]);
            break; 
        case 'O':
            PushToScreen(ktext_in_bytes[14]);
            break; 
        case 'P':
            PushToScreen(ktext_in_bytes[15]);
            break; 
        case 'Q':
            PushToScreen(ktext_in_bytes[16]);
            break; 
        case 'R':
            PushToScreen(ktext_in_bytes[17]);
            break; 
        case 'S':
            PushToScreen(ktext_in_bytes[18]);
            break; 
        case 'T':
            PushToScreen(ktext_in_bytes[19]);
            break; 
        case 'U':
            PushToScreen(ktext_in_bytes[20]);
            break; 
        case 'V':
            PushToScreen(ktext_in_bytes[21]);
            break; 
        case 'W':
            PushToScreen(ktext_in_bytes[22]);
            break; 
        case 'X':
            PushToScreen(ktext_in_bytes[23]);
            break; 
        case 'Y':
            PushToScreen(ktext_in_bytes[24]);
            break; 
        case 'Z':
            PushToScreen(ktext_in_bytes[25]);
            break;
        case ' ':
            PushToScreen(ktext_in_bytes[26]);
            break;
        case '0':
            PushToScreen(ktext_in_bytes[27]);
            break;
        case '1':
            PushToScreen(ktext_in_bytes[28]);
            break;
        case '2':
            PushToScreen(ktext_in_bytes[29]);
            break;
        case '3':
            PushToScreen(ktext_in_bytes[30]);
            break;
        case '4':
            PushToScreen(ktext_in_bytes[31]);
            break;
        case '5':
            PushToScreen(ktext_in_bytes[32]);
            break;
        case '6':
            PushToScreen(ktext_in_bytes[33]);
            break;
        case '7':
            PushToScreen(ktext_in_bytes[34]);
            break;
        case '8':
            PushToScreen(ktext_in_bytes[35]);
            break;
        case '9':
            PushToScreen(ktext_in_bytes[36]);
            break;
        case ':':
            PushToScreen(ktext_in_bytes[37]);
            break;
        case '!':
            PushToScreen(ktext_in_bytes[38]);
            break;

        default:
            break;
    }
  }
}

*/