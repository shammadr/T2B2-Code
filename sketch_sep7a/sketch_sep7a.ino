#include <Adafruit_NeoPixel.h>
#include <DC_Motor.h> 
#include "simple_matrix.h"

#define NUMPIXELS      12 // number of neopixels in strip (very subject to change)
#define textDelay 25 // text delay for the matrix (currently in ms, only required if we keep the left to right, if we want just static dont need)
const char text[] PROGMEM = "testing"; // subject to change after testing

/*
If you notice that the display is upside-down per display, change 
simpleMatrix disp(13); to simpleMatrix disp(13, true);
*/
simpleMatrix disp(13); // pin 13, 12 or 11 (requires testing)

// LED Strip Initialisation
Adafruit_NeoPixel pixelsEntry = Adafruit_NeoPixel(NUMPIXELS, A0, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsPillarOne = Adafruit_NeoPixel(NUMPIXELS, A1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsPillarTwo = Adafruit_NeoPixel(NUMPIXELS, A2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixelsExit = Adafruit_NeoPixel(NUMPIXELS, A3, NEO_GRB + NEO_KHZ800);

// DC Motor Initialisation
DC_Motor motor = motor(4, 5); 

void setup() {
  Serial.begin(9600);
  pixelsEntry.begin();
  pixelsPillarOne.begin();
  pixelsPillarTwo.begin();
  pixelsExit.begin();
  pinMode(2, INPUT) // entrySensor
  pinMode(3, INPUT) // pillarOneSensor
  pinMode(6, INPUT) // pillarTwoSensor
  pinMode(7, INPUT) // exitSensor
  //motor.setSpeed(); requires preliminary testing
  motor.forward(); // subject to change, could be backwards
  disp.begin();
  disp.setIntensity(5); //This value can be anywhere between 0 and 15 (requires testing)
  pinMode(2, INPUT)

}

void loop() {

  disp.scrollTextPROGMEMRightToLeft(text, textDelay); // textdelay requires testing

  // if entrySensor == HIGH -> entryRampLightshow()

  // if pillarOneSensor == HIGH -> pillarOneLightshow()

  // if pillarTwoSensor == HIGH -> pillarTwoLightshow()

  // if exitSensor == HIGH -> exitRampLightshow()

}
