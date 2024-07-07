#include "hardware.h"

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println("Initializing...");
  for (uint8_t p = 0; p < N_RELAY_PINS; p++) {
    pinMode(relay_pins[p], OUTPUT);
  }
  Serial.println("Initialized.");
}

void loop() {
  for (uint8_t p = 0; p < N_RELAY_PINS; p++) {
    digitalWrite(relay_pins[p], HIGH);
    delay(1000);
    digitalWrite(relay_pins[p], LOW);
  }
}
