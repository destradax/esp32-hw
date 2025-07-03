#include "wifi.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "blink.h"

#define INTERVAL_MS 500
#define MAX_RETRIES 20

namespace wifi {

bool connectToWiFi(const char *ssid, const char *passPhrase) {
  Serial.printf("Connecting to WiFi: |%s| ", ssid);

  // WiFi.mode(WIFI_STA);
  // WiFi.setHostname("esp8266hostname");
  WiFi.setPhyMode(WIFI_PHY_MODE_11G);
  WiFi.begin(ssid, passPhrase);

  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries++ <= MAX_RETRIES) {
    Serial.print(".");
    blinkFastTimes(3);
    delay(INTERVAL_MS);
  }

  Serial.println();

  if (retries >= MAX_RETRIES) {
    Serial.println("Could not connect");
    return false;
  }

  Serial.printf("Connected. IP address: |%s| Hostname: |%s|\n",
                WiFi.localIP().toString().c_str(), WiFi.getHostname());

  return true;
}
}  // namespace wifi
