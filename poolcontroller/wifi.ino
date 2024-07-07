#include <WiFi.h>
#include "wifi_auth.h"

void setup_wifi() {
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" wifi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting in 5 seconds...");
    delay(5000);
    ESP.restart();
  }

  Serial.print("Connected to wifi with IP address ");
  Serial.println(WiFi.localIP());
}
