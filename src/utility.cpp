#include "utility.h"
#include "fonts.h"

// функция отрисовки точки по координатам X Y
void drawPixelXY(int8_t x, int8_t y, byte color, byte saturation, byte vol) {
  drawPixelXY(x, y, CHSV(color, saturation, vol));
}

void drawPixelXY(int8_t x, int8_t y, CRGB color) {
  if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1) return;
  int thisPixel = getPixelNumber(x, y);
  leds[thisPixel] = color;
}

// получить номер пикселя в ленте по координатам
uint16_t getPixelNumber(int8_t x, int8_t y) {
  if ((THIS_Y % 2 == 0) || MATRIX_TYPE) {               // если чётная строка
    return (THIS_Y * _WIDTH + THIS_X);
  } else {                                              // если нечётная строка
    return (THIS_Y * _WIDTH + _WIDTH - THIS_X - 1);
  }
}

void drawMcx8VertBitmap(uint8_t posX, uint8_t posY, uint8_t len, const uint8_t data[], CRGB foreground, CRGB background) {
  for (int xi = 0; xi < len; xi++) {
    uint8_t bitmask = data[xi];
    for (int yj = 0; yj < BITMAP_HEIGHT; yj++) {
      drawPixelXY(posX + xi, posY + yj, (bitRead(bitmask,yj) ? foreground : background));
    }
  }
}

void drawSymbol(uint8_t posX, uint8_t symbol, CRGB foreground, CRGB background) {
  // Тут 0 - это координата по X, а 5 - это ширина символа в шрифте
  drawMcx8VertBitmap(posX, 0, 5, numbig[symbol], foreground, background);
}

void drawSymbol(uint8_t posX, uint8_t symbol, CRGB foreground) {
  drawSymbol(posX, symbol, foreground, CRGB::Black);
}
