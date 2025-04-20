#include <WebSocketsClient.h>

#include "credentials.h"
#include "lightbulb.h"

WebSocketsClient webSocket;

void webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
  switch (type) {
    case WStype_CONNECTED:
      Serial.println("Connected to WebSocket server!");
      break;
    case WStype_DISCONNECTED:
      Serial.println("Disconnected from WebSocker server");
      break;
    case WStype_TEXT:
      Serial.printf("Received message: %s\n", payload);
      break;
  }
}

void webSocketSetup() {
  webSocket.begin(webSocketHost, webSocketPort, webSocketPath);
  new Lightbulb(webSocket);
  // webSocket.onEvent(webSocketEvent);
}

void webSocketListen() { webSocket.loop(); }