#include <Arduino.h>

#include "device.h"

bool serverStarted = false;
bool printResult = true;

Device device;

void setup(void) {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.flush();
  Serial.println("Setup done");
}

void loop(void) {
  // keep for indentation
  device.loop();
}