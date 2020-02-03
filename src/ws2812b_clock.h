#pragma once

#include <Arduino.h>
#include <FastLED.h>

#include "config.h"

//Работа с сетью
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <NTPClient.h>


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 10800, 600000);


// ================ НАСТРОЙКИ ================
#define BRIGHTNESS 150         // стандартная яркость (0-255)

#define CURRENT_LIMIT 1000    // лимит по току в миллиамперах, автоматически управляет яркостью (пожалей свой блок питания!) 0 - выключить лимит

// ============ ДЛЯ РАЗРАБОТЧИКОВ ============
// ПИНЫ
#define LED_PIN 4

const int NUM_LEDS = WIDTH * HEIGHT;
CRGB leds[NUM_LEDS];
