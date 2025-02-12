/*******************************************************************************
 * Start of Arduino_GFX setting
 * 
 * Arduino_GFX try to find the settings depends on selected board in Arduino IDE
 * Or you can define the display dev kit not in the board list
 * Defalult pin list for non display dev kit:
 * Arduino Nano, Micro and more: TFT_CS:  9, TFT_DC:  8, TFT_RST:  7, TFT_BL:  6
 * ESP32 various dev board     : TFT_CS:  5, TFT_DC: 27, TFT_RST: 33, TFT_BL: 22
 * ESP32-C3 various dev board  : TFT_CS:  7, TFT_DC:  2, TFT_RST:  1, TFT_BL:  3
 * ESP32-S2 various dev board  : TFT_CS: 34, TFT_DC: 26, TFT_RST: 33, TFT_BL: 21
 * ESP8266 various dev board   : TFT_CS: 15, TFT_DC:  4, TFT_RST:  2, TFT_BL:  5
 * Raspberry Pi Pico dev board : TFT_CS: 17, TFT_DC: 27, TFT_RST: 26, TFT_BL: 28
 * RTL872x various dev board   : TFT_CS: 18, TFT_DC: 17, TFT_RST:  2, TFT_BL: 23
 * Seeeduino XIAO dev board    : TFT_CS:  3, TFT_DC:  2, TFT_RST:  1, TFT_BL:  0
 * Teensy 4.1 dev board        : TFT_CS: 39, TFT_DC: 41, TFT_RST: 40, TFT_BL: 22
 ******************************************************************************/
#include <Arduino_GFX_Library.h>

/* More dev device declaration: https://github.com/moononournation/Arduino_GFX/wiki/Dev-Device-Declaration */
#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */

/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
Arduino_DataBus *bus = create_default_Arduino_DataBus();

/* More display class: https://github.com/moononournation/Arduino_GFX/wiki/Display-Class */
Arduino_GFX *gfx = new Arduino_ILI9341(bus, TFT_RST, 0 /* rotation */, false /* IPS */);

#endif /* !defined(DISPLAY_DEV_KIT) */
/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/

void setup(void)
{
    gfx->begin();
    gfx->fillScreen(BLACK);

#ifdef TFT_BL
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
#endif

    gfx->setTextColor(GREEN);
    for (int x = 0; x < 16; x++)
    {
        gfx->setCursor(10 + x * 8, 2);
        gfx->print(x, 16);
    }
    gfx->setTextColor(BLUE);
    for (int y = 0; y < 16; y++)
    {
        gfx->setCursor(2, 12 + y * 10);
        gfx->print(y, 16);
    }

    char c = 0;
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < 16; x++)
        {
            gfx->drawChar(10 + x * 8, 12 + y * 10, c++, WHITE, BLACK);
        }
    }

    delay(5000); // 5 seconds
}

void loop()
{
}