#include <FastLED.h>

// joystick nastavitve
const int VRx = A0;
const int SW  = 2;

int value = 27;
int minValue = 0;
int maxValue = 53;

// FastLED nastavitve
#define LED_PIN     6
#define NUM_LEDS    54
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

// barve
CRGB colors[] = {CRGB::Blue, CRGB::Red, CRGB::Green, CRGB::Yellow, CRGB::Purple};
int colorIndex = 0;
int numColors = sizeof(colors) / sizeof(colors[0]);

// za zaznavo gumba (debounce)
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(225);  // nastavi svetlost od 0 do 255

  FastLED.clear();
  FastLED.show();

  Serial.println("🎮 Joystick: levo/desno za premik, gumb za spremembo barve");
}

void loop() {
  int xVal = analogRead(VRx);
  int deadzone = 27;

  // premik desno
  if (xVal > 512 + deadzone) {
    value++;
    if (value > maxValue) value = maxValue;
    Serial.print("➡️ LED index: ");
    Serial.println(value);
    updateLEDs();
    delay(50);
  }

  // premik levo
  else if (xVal < 512 - deadzone) {
    value--;
    if (value < minValue) value = minValue;
    Serial.print("⬅️ LED index: ");
    Serial.println(value);
    updateLEDs();
    delay(50);
  }

  // preveri gumb (za menjavo barve)
  bool currentButtonState = digitalRead(SW);

  if (currentButtonState == LOW && lastButtonState == HIGH && (millis() - lastDebounceTime) > debounceDelay) {
    gumb je pravkar pritisnjen
    colorIndex++;
    if (colorIndex >= numColors) colorIndex = 0;

    Serial.print("🎨 Nova barva: ");
    Serial.println(colorIndex);

    updateLEDs();
    lastDebounceTime = millis();
  }

  lastButtonState = currentButtonState;
}

// posodobi LED
void updateLEDs() {
  FastLED.clear();
  leds[value] = colors[colorIndex];
  FastLED.show();
}