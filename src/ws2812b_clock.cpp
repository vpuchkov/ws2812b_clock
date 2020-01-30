#include "ws2812b_clock.h"

#include "utility.h"

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