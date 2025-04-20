#include <WebSocketsClient.h>
#include "lightbulb.h"

void Lightbulb::webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
  switch (type) {
    case WStype_CONNECTED:
      Serial.println("Connected to WebSocket server!");
      break;
    case WStype_DISCONNECTED:
      Serial.println("Disconnected from WebSocker server");
      break;
    case WStype_TEXT:
      this->processCommand(payload);
      break;
  }
}

void Lightbulb::processCommand(uint8_t* payload) {
  Serial.printf("Processing message: %s\n", payload);
}