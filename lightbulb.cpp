#include <WebSocketsClient.h>

class Lightbulb {
 public:
  Lightbulb(WebSocketsClient webSocket) {
    webSocket.onEvent(this->webSocketEvent);
  }

  void processCommand(uint8_t* payload) {
    Serial.printf("Processing message: %s\n", payload);
  }

  void webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
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
}