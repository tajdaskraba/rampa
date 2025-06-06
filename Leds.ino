#include <FastLED.h>
#define ST_LEDIC 1
#define DATA_PIN 6
#define BRIGHTNESS 5

CRGB trak[ST_LEDIC];

   void setup() { 
       FastLED.addLeds<NEOPIXEL, DATA_PIN>(trak, ST_LEDIC);
   }

    void loop() {
        for(int lucka = 0; lucka < ST_LEDIC; lucka++) { 
            trak[lucka] = CRGB::White;
            FastLED.show();
            trak[lucka] = CRGB::Black;
            delay(30);
        }
    }
