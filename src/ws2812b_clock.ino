/*
  Скетч к проекту "Бегущая строка"
  Страница проекта (схемы, описания): https://alexgyver.ru/GyverString/
  Исходники на GitHub: https://github.com/AlexGyver/GyverString/
  Нравится, как написан код? Поддержи автора! https://alexgyver.ru/support_alex/
  Автор: AlexGyver, AlexGyver Technologies, 2019
  https://AlexGyver.ru/
*/

// ================ НАСТРОЙКИ ================
#define BRIGHTNESS 150         // стандартная яркость (0-255)

#define CURRENT_LIMIT 1000    // лимит по току в миллиамперах, автоматически управляет яркостью (пожалей свой блок питания!) 0 - выключить лимит

#define WIDTH 27              // ширина матрицы
#define HEIGHT 7              // высота матрицы

#define COLOR_ORDER GRB       // порядок цветов на ленте. Если цвет отображается некорректно - меняйте. Начать можно с RGB

#define MATRIX_TYPE 0         // тип матрицы: 0 - зигзаг, 1 - параллельная
#define CONNECTION_ANGLE 3    // угол подключения: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний
#define STRIP_DIRECTION 2     // направление ленты из угла: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз
// при неправильной настрйоке матрицы вы получите предупреждение "Wrong matrix parameters! Set to default"
// шпаргалка по настройке матрицы здесь! https://alexgyver.ru/matrix_guide/

// ============ ДЛЯ РАЗРАБОТЧИКОВ ============
// ПИНЫ
#define LED_PIN 4

// БИБЛИОТЕКИ
#include <FastLED.h>
//#include "fonts.h"

byte numbig[11][5]={{B01111111,B01000001,B01000001,B01000001,B01111111}, //0
                 {B00100001,B00100001,B01111111,B00000001,B00000001}, //1
                 {B01001111,B01001001,B01001001,B01001001,B01111001}, //2
                 {B01001001,B01001001,B01001001,B01001001,B01111111}, //3
                 {B01111000,B00001000,B00001000,B00001000,B01111111}, //4
                 {B01111001,B01001001,B01001001,B01001001,B01001111}, //5
                 {B01111111,B01001001,B01001001,B01001001,B01001111}, //6
                 {B01000000,B01000000,B01000000,B01000000,B01111111}, //7
                 {B01111111,B01001001,B01001001,B01001001,B01111111}, //8
                 {B01111001,B01001001,B01001001,B01001001,B01111111}, //9
                 {B00010100},// двоеточие
      };

byte numsmall[11][3]={{B00111110,B00100010,B00111110}, //0
                 {B00010010,B00111110,B00000010}, //1
                 {B00101110,B00101010,B00111010}, //2
                 {B00101010,B00101010,B00111110}, //3
                 {B00111000,B00001000,B00111110}, //4
                 {B00111010,B00101010,B00101110}, //5
                 {B00111110,B00101010,B00101110}, //6
                 {B00100000,B00100000,B00111110}, //7
                 {B00111110,B00101010,B00111110}, //8
                 {B00111010,B00101010,B00111110}, //9
                 {B00010100},// двоеточие
      };

const int NUM_LEDS = WIDTH * HEIGHT;
CRGB leds[NUM_LEDS];


void setup() {
  Serial.begin(9600);

  // настройки ленты
  FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
  if (CURRENT_LIMIT > 0) FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
  FastLED.clear();
  FastLED.show();
}

#define BITMAP_HEIGHT 8
void drawMcx8VertBitmap(uint8_t posX, uint8_t posY, uint8_t len, uint8_t data[], CRGB foreground, CRGB background) {
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

void loop() {
//1
  drawSymbol(1, 4, CRGB(60, 255, 255), CRGB(140, 180, 0));
//2
  drawSymbol(7, 5, CRGB(60, 255, 255));
//:
  drawSymbol(13, 10, CRGB(60, 255, 255), CRGB(140, 180, 0));
//3
  drawSymbol(15, 8, CRGB(60, 255, 255));
//4
  drawSymbol(21, 9, CRGB(60, 255, 255), CRGB(140, 180, 0));

      FastLED.show();
      delay(200);
  
  
}