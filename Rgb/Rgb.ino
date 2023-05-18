#include "CubeCell_NeoPixel.h"
CubeCell_NeoPixel pixels(1, RGB, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext,LOW); //SET POWER
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear(); // Set all pixel colors to 'off'
}
uint8_t i=0;

#define DELAY 3

void loop() {
  // put your main code here, to run repeatedly:

    //red to yellow
    for (int i = 1; i < 256; i++) {
      pixels.setPixelColor(0, pixels.Color(255, i, 0));
      pixels.show();
      delay(DELAY);
    }

    // yellow to green
    for (int i = 255; i > 0; i--) {
      pixels.setPixelColor(0, pixels.Color(i, 255, 0));
      pixels.show();
      delay(DELAY);
    }

    for (int i = 1; i < 256; i++) {
      pixels.setPixelColor(0, pixels.Color(0, 255, i));
      pixels.show();
      delay(DELAY);
    }

    for (int i = 255; i > 0; i--) {
      pixels.setPixelColor(0, pixels.Color(0, i, 255));
      pixels.show();
      delay(DELAY);
    }

    for (int i = 1; i < 256; i++) {
      pixels.setPixelColor(0, pixels.Color(i, 0, 255));
      pixels.show();
      delay(DELAY);
    }

    for (int i = 255; i > 0; i--) {
      pixels.setPixelColor(0, pixels.Color(255, 0, i));
      pixels.show();
      delay(DELAY);
    }
}
