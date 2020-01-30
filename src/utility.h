#pragma once

#include <stdlib.h>
#include <FastLED.h>

#include "config.h"

// **************** НАСТРОЙКА МАТРИЦЫ ****************
#if (CONNECTION_ANGLE == 0 && STRIP_DIRECTION == 0)
    #define _WIDTH WIDTH
    #define THIS_X x
    #define THIS_Y y
#elif (CONNECTION_ANGLE == 0 && STRIP_DIRECTION == 1)
    #define _WIDTH HEIGHT
    #define THIS_X y
    #define THIS_Y x
#elif (CONNECTION_ANGLE == 1 && STRIP_DIRECTION == 0)
    #define _WIDTH WIDTH
    #define THIS_X x
    #define THIS_Y (HEIGHT - y - 1)
#elif (CONNECTION_ANGLE == 1 && STRIP_DIRECTION == 3)
    #define _WIDTH HEIGHT
    #define THIS_X (HEIGHT - y - 1)
    #define THIS_Y x
#elif (CONNECTION_ANGLE == 2 && STRIP_DIRECTION == 2)
    #define _WIDTH WIDTH
    #define THIS_X (WIDTH - x - 1)
    #define THIS_Y (HEIGHT - y - 1)
#elif (CONNECTION_ANGLE == 2 && STRIP_DIRECTION == 3)
    #define _WIDTH HEIGHT
    #define THIS_X (HEIGHT - y - 1)
    #define THIS_Y (WIDTH - x - 1)
#elif (CONNECTION_ANGLE == 3 && STRIP_DIRECTION == 2)
    #define _WIDTH WIDTH
    #define THIS_X (WIDTH - x - 1)
    #define THIS_Y y
#elif (CONNECTION_ANGLE == 3 && STRIP_DIRECTION == 1)
    #define _WIDTH HEIGHT
    #define THIS_X y
    #define THIS_Y (WIDTH - x - 1)
#else
    #define _WIDTH WIDTH
    #define THIS_X x
    #define THIS_Y y
    #pragma message "Wrong matrix parameters! Set to default"
#endif

extern CRGB leds[];

void drawPixelXY(int8_t x, int8_t y, byte color, byte saturation, byte vol);

void drawPixelXY(int8_t x, int8_t y, CRGB color);

uint16_t getPixelNumber(int8_t x, int8_t y);

void drawMcx8VertBitmap(uint8_t posX, uint8_t posY, uint8_t len, uint8_t data[], CRGB foreground, CRGB background);

void drawSymbol(uint8_t posX, uint8_t symbol, CRGB foreground, CRGB background);

void drawSymbol(uint8_t posX, uint8_t symbol, CRGB foreground);