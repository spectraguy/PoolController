uint8_t relay_pins[] = {32, 33, 25, 26, 27, 14, 12, 13};

void setup_hardware() {
  for (uint8_t p = 0; p < N_RELAYS; p++) {
    pinMode(relay_pins[p], OUTPUT);
  }
}

void set_relay(uint8_t relay, bool on) {
  if (relay >= N_RELAYS) {
    Serial.println("Tried to set non-existent relay!");
    return;
  }

  digitalWrite(relay_pins[relay], on ? HIGH : LOW);
}
