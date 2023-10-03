#include <FastLED.h>

#define NUM_LEDS 20     /* The amount of pixels/leds */
#define DATA_PIN 7       
#define LED_TYPE WS2812B 
#define BRIGHTNESS 255   /* Control the brightness of your leds */
#define SATURATION 255   /* Control the saturation of your leds */

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {

    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i].setRGB(255, 0, 0) /* The higher the value 4 the less fade there is and vice versa */ 
    FastLED.show();
    delay(25); /* Change this to your hearts desire, the lower the value the faster your colors move (and vice versa) */
  }
}
