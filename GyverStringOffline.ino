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

byte num[11][5]={{B01111111,B01000001,B01000001,B01000001,B01111111}, //0
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
//1
  for (int xi=0; xi<5;xi++) {
    for (int yj=0; yj<HEIGHT;yj++) {
      if (bitRead(num[4][xi],yj)==1) {
      drawPixelXY(1+xi, yj, 60, 255, 255);
      }
      if (bitRead(num[4][xi],yj)==0) {
      drawPixelXY(1+xi, yj, 140, 180, 0);
      }
    }
    
  }
//2
   for (int xi=0; xi<5;xi++) {
    for (int yj=0; yj<HEIGHT;yj++) {
      if (bitRead(num[5][xi],yj)==1) {
      drawPixelXY(7+xi, yj, 60, 255, 255);
      }
      if (bitRead(num[5][xi],yj)==0) {
      drawPixelXY(7+xi, yj, 140, 180, 0);
      }
    }
   }
//:
   for (int xi=0; xi<1;xi++) {
    for (int yj=0; yj<HEIGHT;yj++) {
      if (bitRead(num[10][xi],yj)==1) {
      drawPixelXY(13+xi, yj, 60, 255, 255);
      }
      if (bitRead(num[10][xi],yj)==0) {
      drawPixelXY(13+xi, yj, 140, 180, 0);
      }
    }
  }
//3
   for (int xi=0; xi<5;xi++) {
    for (int yj=0; yj<HEIGHT;yj++) {
      if (bitRead(num[8][xi],yj)==1) {
      drawPixelXY(15+xi, yj, 60, 255, 255);
      }
      if (bitRead(num[8][xi],yj)==0) {
      drawPixelXY(15+xi, yj, 140, 180, 0);
      }
    }
  }
//4
   for (int xi=0; xi<5;xi++) {
    for (int yj=0; yj<HEIGHT;yj++) {
      if (bitRead(num[9][xi],yj)==1) {
      drawPixelXY(21+xi, yj, 60, 255, 255);
      }
      if (bitRead(num[9][xi],yj)==0) {
      drawPixelXY(21+xi, yj, 140, 180, 0);
      }
    }
  }
      FastLED.show();
      delay(200);
  
  
}