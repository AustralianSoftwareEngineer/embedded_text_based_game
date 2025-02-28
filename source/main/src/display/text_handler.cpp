#include "text_handler.hpp"

const unsigned char ktext_in_bytes_array[][7] = {
  {0x1E, 0x05, 0x05, 0x05, 0x1E, 0x00, 'A'}, // A 0
  {0x1F, 0x15, 0x15, 0x16, 0x1C, 0x00, 'B'}, // B 1
  {0x1F, 0x11, 0x11, 0x11, 0x11, 0x00, 'C'}, // C 2
  {0x1F, 0x11, 0x11, 0x11, 0x0E, 0x00, 'D'}, // D 3
  {0x1F, 0x15, 0x15, 0x15, 0x15, 0x00, 'E'}, // E 4
  {0x1F, 0x05, 0x05, 0x05, 0x05, 0x00, 'F'}, // F 5
  {0x1F, 0x11, 0x11, 0x15, 0x1D, 0x00, 'G'}, // G 6
  {0x1F, 0x04, 0x04, 0x04, 0x1F, 0x00, 'H'}, // H 7
  {0x11, 0x11, 0x1F, 0x11, 0x11, 0x00, 'I'}, // I 8
  {0x11, 0x11, 0x1F, 0x01, 0x01, 0x00, 'J'}, // J 9
  {0x1F, 0x04, 0x04, 0x0A, 0x11, 0x00, 'K'}, // K 10
  {0x1F, 0x10, 0x10, 0x10, 0x10, 0x00, 'L'}, // L 11
  {0x1F, 0x01, 0x02, 0x01, 0x1F, 0x00, 'M'}, // M 12
  {0x1F, 0x01, 0x02, 0x04, 0x1F, 0x00, 'N'}, // N 13
  {0x1F, 0x11, 0x11, 0x11, 0x1F, 0x00, 'O'}, // O 14
  {0x1F, 0x05, 0x05, 0x05, 0x07, 0x00, 'P'}, // P 15
  {0x1F, 0x11, 0x15, 0x09, 0x17, 0x00, 'Q'}, // Q 16
  {0x1F, 0x05, 0x0D, 0x1D, 0x17, 0x00, 'R'}, // R 17
  {0x17, 0x15, 0x15, 0x15, 0x19, 0x00, 'S'}, // S 18
  {0x01, 0x01, 0x1F, 0x01, 0x01, 0x00, 'T'}, // T 19
  {0x1F, 0x10, 0x10, 0x10, 0x1F, 0x00, 'U'}, // U 20
  {0x03, 0x0C, 0x10, 0x0C, 0x03, 0x00, 'V'}, // V 21
  {0x0F, 0x10, 0x08, 0x10, 0x0F, 0x00, 'W'}, // W 22
  {0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, 'X'}, // X 23
  {0x03, 0x04, 0x1C, 0x04, 0x03, 0x00, 'Y'}, // Y 24
  {0x19, 0x15, 0x15, 0x15, 0x17, 0x00, 'Z'}, // Z 25

  //Numerals & Special characters
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, ' '}, //' '26
  {0x1F, 0x11, 0x15, 0x11, 0x1F, 0x00, '0'}, // 0 27
  {0x10, 0x12, 0x1F, 0x10, 0x10, 0x00, '1'}, // 1 28
  {0x1D, 0x15, 0x15, 0x15, 0x17, 0x00, '2'}, // 2 29
  {0x15, 0x15, 0x15, 0x15, 0x1F, 0x00, '3'}, // 3 30
  {0x07, 0x04, 0x04, 0x1F, 0x04, 0x00, '4'}, // 4 31
  {0x17, 0x15, 0x15, 0x15, 0x1D, 0x00, '5'}, // 5 32
  {0x1F, 0x15, 0x15, 0x15, 0x1D, 0x00, '6'}, // 6 33
  {0x01, 0x01, 0x01, 0x01, 0x1F, 0x00, '7'}, // 7 34
  {0x1F, 0x15, 0x15, 0x15, 0x1F, 0x00, '8'}, // 8 35
  {0x07, 0x05, 0x05, 0x05, 0x1F, 0x00, '9'}, // 9 36
  {0x00, 0x0A, 0x0A, 0x0A, 0x00, 0x00, ':'}, // : 37
  {0x00, 0x17, 0x00, 0x00, 0x00, 0x00, '!'},  // ! 38


  // Not implemented and just spaces to prevent visual issues.
  {0x10, 0x18, 0x0C, 0x04, 0x00, 0x00, ','}, // , --
  {0x04, 0x06, 0x03, 0x01, 0x00, 0x00, 0x27},// ' --
  {0x00, 0x03, 0x01, 0x15, 0x03, 0x00, '?'} //  ? --
};

const uint8_t kmax_characters_implemented = sizeof(ktext_in_bytes_array) / sizeof(ktext_in_bytes_array[0]);
const uint16_t kdialogue_max_length = 500;

//If implementing a method to check that the word will fit do something like...
//Get char push to new array; new array length == size_of_dialogue;

static void I2CDialoguePusher(const unsigned char* dialogue_message, uint8_t size_of_dialogue)
{
  uint8_t current_cursor_line = 2;
  uint8_t counting = 3;
  FillScreen(0x00, 0x01, 0x00);
  MoveCursor(0x01, 0x00);
  if ((size_of_dialogue * 5) > kdialogue_max_length)
  {
    Serial.println("Size of dialogue was too large.");
    return;
  }
  for (uint8_t i = 0; i != size_of_dialogue; i++)
  {
    if (counting == 24)
    {
      MoveCursor(current_cursor_line, 0x00);
      counting++;
    }
    counting++;
    unsigned char data = I2CTextVerification(dialogue_message[i]);
    for (uint8_t j = 0; j < kmax_characters_implemented; j++)
    {
      //Serial.println("Data assignment loop check eneterd.");
      if (data == ktext_in_bytes_array[j][6])
      {
        PushToScreen((unsigned char*)ktext_in_bytes_array[j]);
        break;
      }
    }
  }
}

//Depreciated
static void I2CDialogueFromFlashPusher(const unsigned char dialogue_byte)
{
  for (uint8_t j = 0; j < 39; j++)
  {
    if (dialogue_byte == ktext_in_bytes_array[j][6])
    {
      PushToScreen((unsigned char*)ktext_in_bytes_array[j]);
    }
  }
}

//Depreciated
static void I2CTextPusher(const unsigned char *message, uint8_t size_of_message) 
{
  for (uint8_t i = 0; i < size_of_message; i++)
  {
    unsigned char data = I2CTextVerification(message[i]);
    for (uint8_t j = 0; j < 39; j++)
    {
      if (data == ktext_in_bytes_array[j][6])
      {
        PushToScreen((unsigned char*)ktext_in_bytes_array[j]);
        break;
      }
    }
  }
}


static unsigned char I2CTextVerification(unsigned char message)
{
  unsigned char data = message;
  if ((int)data > 92)
  {
    data -= 32;
  }
  return data;
}
