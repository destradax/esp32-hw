#include "blink.h"

#include <Arduino.h>

void turnOn() { digitalWrite(LED_BUILTIN, LOW); }

void turnOff() { digitalWrite(LED_BUILTIN, HIGH); }

void turnOnForMillis(unsigned long millis) {
  turnOn();
  delay(millis);
  turnOff();
}

void blinkFor(unsigned int blinkDuration, unsigned int stopDuration) {
  turnOnForMillis(blinkDuration);
  delay(stopDuration);
}

void blinkSlow() { blinkFor(750, 750); }

void blink() { blinkFor(500, 500); }

void blinkFast() { blinkFor(250, 250); }

void blinkSlowTimes(unsigned int times) {
  for (unsigned int i = 0; i < times; i++) {
    blinkSlow();
  }
}

void blinkTimes(unsigned int times) {
  for (unsigned int i = 0; i < times; i++) {
    blink();
  }
}

void blinkFastTimes(unsigned int times) {
  for (unsigned int i = 0; i < times; i++) {
    blinkFast();
  }
}