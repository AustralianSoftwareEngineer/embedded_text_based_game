#include "i2c_handler.h"

const char kscreen_address = 0x3C;
const uint16_t ktotal_bytes  = 1024;
const uint8_t kmax_vertical_lines  = 7;
const uint8_t kmax_horizontal_lines  = 128;

uint8_t previous_line_number   = 0;             // Save the specified line number
uint8_t previous_cursor_position = 0;          // Save the specified cursor position



static void WriteToScreen(bool is_command_byte, unsigned char data) {
    unsigned char buffer[2] = {0};
    (is_command_byte == true) ? buffer[0] = 0x00 : buffer[0] = 0x40;
    buffer[1] = data;

    Wire.beginTransmission(kscreen_address);
    Wire.write(buffer, 2);
    Wire.endTransmission();
}

static void FillScreen(unsigned char data) {
    for(uint16_t i = 0; i < ktotal_bytes; i++)
    {
        WriteToScreen(false, data);
        delay(1);
    }
}

/*static void PushToScreen(unsigned char data) {
    WriteToScreen(false, data);
}*/

static void PushToScreen(unsigned char *data) {
  for (int i = 0; i < 6; i++)
  {
    WriteToScreen(false, data[i]);
  }
}

static void FillScreenAlternating(unsigned char data, unsigned char data_other) {
    for(uint16_t i = 0; i < ktotal_bytes; i++)
    {
        if (i % 2 == 0)
        {
          WriteToScreen(false, data);
        }
        else
        {
          WriteToScreen(false, data_other);
        }
    }
}

static void  MoveToNextLine() {
  previous_line_number++;
  previous_line_number = (previous_line_number & kmax_vertical_lines);
  MoveCursor(previous_line_number,0);
}

static void MoveCursor(uint8_t new_line, uint8_t new_cursor) {
  if((new_line <= kmax_vertical_lines) && (previous_cursor_position < kmax_horizontal_lines))
  {

    WriteToScreen(true, 0x21);                    // cmd for the column start and end address
    WriteToScreen(true, new_cursor);              // column start addr
    WriteToScreen(true, kmax_horizontal_lines-1); // column end addr
    WriteToScreen(true, 0x22);                    // cmd for the page start and end address
    WriteToScreen(true, new_line);                // page start addr
    WriteToScreen(true, kmax_vertical_lines);     // page end addr
  }
}

static void DisplaySetupCommands() {

    WriteToScreen(true, 0xAE); // Entire Display OFF
    WriteToScreen(true, 0xD5); // Set Display Clock Divide Ratio and Oscillator Frequency
    WriteToScreen(true, 0x80); // Default Setting for Display Clock Divide Ratio and Oscillator Frequency that is recommended
    WriteToScreen(true, 0xA8); // Set Multiplex Ratio
    WriteToScreen(true, 0x3F); // 64 COM lines
    WriteToScreen(true, 0xD3); // Set display offset
    WriteToScreen(true, 0x00); // 0 offset
    WriteToScreen(true, 0x40); // Set first line as the start line of the display
    WriteToScreen(true, 0x8D); // Charge pump
    WriteToScreen(true, 0x14); // Enable charge dump during display on
    WriteToScreen(true, 0x20); // Set memory addressing mode
    WriteToScreen(true, 0x00); // Horizontal addressing mode
    WriteToScreen(true, 0xA1); // Set segment remap with column address 127 mapped to segment 0
    WriteToScreen(true, 0xC8); // Set com output scan direction, scan from com63 to com 0
    WriteToScreen(true, 0xDA); // Set com pins hardware configuration
    WriteToScreen(true, 0x12); // Alternative com pin configuration, disable com left/right remap
    WriteToScreen(true, 0x81); // Set contrast control
    WriteToScreen(true, 0x80); // Set Contrast to 128
    WriteToScreen(true, 0xD9); // Set pre-charge period
    WriteToScreen(true, 0xF1); // Phase 1 period of 15 DCLK, Phase 2 period of 1 DCLK
    WriteToScreen(true, 0xDB); // Set Vcomh deselect level
    WriteToScreen(true, 0x20); // Vcomh deselect level ~ 0.77 Vcc
    WriteToScreen(true, 0xA4); // Entire display ON, resume to RAM content display
    WriteToScreen(true, 0xA6); // Set Display in Normal Mode, 1 = ON, 0 = OFF
    WriteToScreen(true, 0x2E); // Deactivate scroll
    WriteToScreen(true, 0xAF); // Display ON in normal mode

}