#include <Wire.h>  
#include "HT_SSD1306Wire.h"

SSD1306Wire  display(0x3c, 500000, SDA, SCL, GEOMETRY_128_64, GPIO10); // addr , freq , SDA, SCL, resolution , rst

void VextON(void)
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, LOW);
}

void setup() {
  VextON();
  delay(100);

  display.init();
  display.clear();
  display.display();
  display.setContrast(255);
}

int cx = 0;
int cy = 0;

int size = display.getHeight() / 6;

int ax = size / 5;
int ay = size / 5;

void loop() {

  display.clear();
  display.fillRect(cx, cy, size, size);
  display.display();

  cx += ax;
  cy += ay;

  if (cy + size == display.getHeight()) {
    ay = -size / 5;
  }

  if (cx + size == display.getWidth()) {
    ax = -size / 5;
  }

  if (cy - size == 0) {
    ay = size / 5;
  }

  if (cx - size == 0) {
    ax = size / 5;
  }

  delay(10);
}