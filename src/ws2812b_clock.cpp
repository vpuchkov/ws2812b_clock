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

const uint8_t bitmap[1] = { B01001111 };
drawMcx8VertBitmap(2, 0, sizeof(bitmap), bitmap, CRGB::Yellow, CRGB::DarkGray);

      FastLED.show();
      delay(200);
  
  
}