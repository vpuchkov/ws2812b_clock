// тест правка от лина

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
#define LED_PIN 2

// БИБЛИОТЕКИ
#include <FastLED.h>
//#include "fonts.h"

byte num[23][4]={{B01111110,B01000010,B01111110,B00000000}, //0
                     {B01000100,B01111110,B01000000,B00000000}, //1
                     {B01100100,B01010010,B01001100,B00000000}, //2
                     {B01000010,B01001010,B01111110,B00000000}, //3
                     {B00111000,B00100100,B01111110,B00000000}, //4
                     {B01001110,B01001010,B01111010,B00000000}, //5
                     {B01111110,B01001010,B01111010,B00000000}, //6
                     {B01100010,B00010010,B00001110,B00000000}, //7
                     {B01111110,B01001010,B01111110,B00000000}, //8
                     {B01001110,B01001010,B01111110,B00000000}, //9
                     {B00001000,B00011100,B00001000,B00000000}, //+
                     {B00001000,B00001000,B00001000,B00000000}, //-
                     {B01111110,B00000010,B01111110,B00000000},//П
                     {B01111110,B01001010,B01110100,B00000000}, //В
                     {B01111110,B01000010,B01100110,B00000000}, //С
                     {B00011110,B00010000,B01111110,B00000000}, //Ч
                     {B01111100,B00010000,B01111100,B00000000},//н
                     {B00000100,B01111100,B00000100,B00000000},//т
                     {B01111100,B00010100,B00011100,B00000000},//р
                     {B01111100,B01010100,B01100100,B00000000},//б
                     {B01111100,B01000100,B01101100,B00000000},//с
                     {B00000000,B00001110,B00001010,B00001110},// градусы
                     {B00000000,B00000000,B00000000,B00000000}// пустота
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

void loop() {

  for (int xi=0; xi<4;xi++) {
    for (int yj=0; yj<HEIGHT;yj++) {
      if (bitRead(num[0][xi],yj)==1) {
      drawPixelXY(xi, yj, 15, 0, 30);
      }
      if (bitRead(num[0][xi],yj)==0) {
      drawPixelXY(xi, yj, 15, 0, 0);
      }
    }
    
  }
  
//  for (byte x = 0; x < WIDTH; x++) {
//    for (byte y = 0; y < HEIGHT; y++) {
//      drawPixelXY(x, y, 15, 16, 17);
      FastLED.show();
      delay(200);
//    }  
  
  
}
