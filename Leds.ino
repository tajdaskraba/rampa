#include <FastLED.h>
#define NUM_LEDS 144
#define DATA_PIN 6
#define BRIGHTNESS 5

CRGB leds[NUM_LEDS];

   void setup() { 
       FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
   }

    void loop() {
        for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot] = CRGB::Blue;
            FastLED.show();
            leds[dot] = CRGB::Black;
            delay(30);
        }
    }
