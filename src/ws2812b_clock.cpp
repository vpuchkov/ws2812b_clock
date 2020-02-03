#include "ws2812b_clock.h"

#include "utility.h"

void setup() {
  Serial.begin(115200);

  // настройки ленты
  FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
  if (CURRENT_LIMIT > 0) FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
  FastLED.clear();
  FastLED.show();

  // настройка сети
  WiFiManager wifiManager;
  wifiManager.autoConnect("ClockAutoConnectAP");
  timeClient.begin();
}


void loop() {

//1
  drawSymbol(1, ( timeClient.getMinutes()  % 100 / 10 ), CRGB(60, 255, 255));
//2
  drawSymbol(7, ( timeClient.getMinutes()  % 10 ), CRGB(60, 255, 255));
//:
  drawSymbol(13, 10, CRGB(60, 255, 255));
//3
  drawSymbol(15, ( timeClient.getSeconds() % 100 / 10 ), CRGB(60, 255, 255));
//4
  drawSymbol(21, ( timeClient.getSeconds() % 10 ), CRGB(60, 255, 255));

FastLED.show();
delay(100);
  
  timeClient.update();

  Serial.println(timeClient.getSeconds());
  
}