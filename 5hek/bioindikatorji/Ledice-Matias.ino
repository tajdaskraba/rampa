#include <FastLED.h>
#define ST_LEDIC 144
#define DATA_PIN 6

CRGB trak[ST_LEDIC];

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(trak, ST_LEDIC);
  FastLED.setBrightness(100);
}

void loop() {
  for(int lucka = 0; lucka < ST_LEDIC; lucka++) {
    int luckab11 = lucka+1;
    int luckab12 = luckab11+1;
    int luckab13 = luckab12+1;
    int luckab21 = luckab13+1;
    int luckab22 = luckab21+1;
    int luckab23 = luckab22+1;
    int luckab31 = luckab23+1;
    int luckab32 = luckab31+1;
    int luckab33 = luckab32+1;
    int luckab41 = luckab33+1;
    int luckab42 = luckab41+1;
    int luckab43 = luckab42+1;

    trak[luckab11] = CRGB::Red;
    trak[luckab12] = CRGB::Red;
    trak[luckab13] = CRGB::Red;
    trak[luckab21] = CRGB::Green;
    trak[luckab22] = CRGB::Green;
    trak[luckab23] = CRGB::Green;
    trak[luckab31] = CRGB::Magenta;
    trak[luckab32] = CRGB::Magenta;
    trak[luckab33] = CRGB::Magenta;
    trak[luckab41] = CRGB::Aqua;
    trak[luckab42] = CRGB::Aqua;
    trak[luckab43] = CRGB::Aqua;

    FastLED.show();

    trak[luckab11] = CRGB::Black;
    trak[luckab12] = CRGB::Black;
    trak[luckab13] = CRGB::Black;
    trak[luckab21] = CRGB::Black;
    trak[luckab22] = CRGB::Black;
    trak[luckab23] = CRGB::Black;
    trak[luckab31] = CRGB::Black;
    trak[luckab32] = CRGB::Black;
    trak[luckab33] = CRGB::Black;
    trak[luckab41] = CRGB::Black;
    trak[luckab42] = CRGB::Black;
    trak[luckab43] = CRGB::Black;
         
    delay(1);
  } 
}