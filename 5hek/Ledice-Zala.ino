#include <FastLED.h>
#define ST_LEDIC 164
#define DATA_PIN 6

CRGB trak[ST_LEDIC];

void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(trak, ST_LEDIC);
}

void loop() {
  for(int lucka = 0; lucka < ST_LEDIC; lucka++) { 
    int lucka1 = lucka + 1;
    int lucka2 = lucka + 2;
    int lucka3 = lucka + 3;
    int lucka4 = lucka + 4;
    int lucka5 = lucka + 5;
    int lucka6 = lucka + 6;
    int lucka7 = lucka + 7;
    int lucka8 = lucka + 8;
    int lucka9 = lucka + 9;
    int lucka10 = lucka + 10;
    int lucka11 = lucka + 11;
    int lucka12 = lucka + 12;
    
    trak[lucka] = CRGB::Red;
    FastLED.show();
    trak[lucka1] = CRGB::Orange;
    FastLED.show();
    trak[lucka2] = CRGB::Yellow;
    FastLED.show();
    trak[lucka3] = CRGB::Green;
    FastLED.show();
    trak[lucka4] = CRGB::Blue;
    FastLED.show();
    trak[lucka5] = CRGB::Magenta;
    FastLED.show();
    trak[lucka6] = CRGB::Purple;
    FastLED.show();
    trak[lucka7] = CRGB::Orange;
    FastLED.show();
    trak[lucka8] = CRGB::Yellow;
    FastLED.show();
    trak[lucka9] = CRGB::Green;
    FastLED.show();
    trak[lucka10] = CRGB::Blue;
    FastLED.show();
    trak[lucka11] = CRGB::Magenta;
    FastLED.show();
    trak[lucka12] = CRGB::Purple;
    FastLED.show();
    trak[lucka] = CRGB::Black;
    delay(0.01);
  }
}