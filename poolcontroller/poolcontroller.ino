#include "hardware.h"

uint8_t current_relay;
unsigned long t_prev_relay;

void setup() {
  // Allow some time to recover from undesirable behavior
  delay(1000);

  // Begin serial communication on main port
  Serial.begin(115200);
  Serial.println("Initializing...");

  // Set up WiFi (including connecting to network)
  setup_wifi();

  // Set up over-the-air uploads
  setup_ota();

  // Configure ESP hardware
  setup_hardware();

  // Start web server
  setup_server();

  // Set initial conditions
  current_relay = N_RELAYS - 1;
  t_prev_relay = millis();

  // Indicate completion of setup
  Serial.println("Initialized.");
}

void loop() {
  unsigned long t = millis();
  if (t > t_prev_relay + 3000) {
    set_relay(current_relay, false);
    current_relay++;
    if (current_relay >= N_RELAYS) {
      current_relay = 0;
    }
    set_relay(current_relay, true);
    t_prev_relay = t;
  }

  poll_ota();
  poll_server();
}

uint8_t get_current_relay() {
  return current_relay;
}
