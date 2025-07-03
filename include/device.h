#ifndef DEVICE_H
#define DEVICE_H

#include <ArduinoWebsockets.h>

class Device {
 private:
  bool isConnectedToWiFi;
  bool isConnectedToWebSocket;
  websockets::WebsocketsClient webSocket;

  void connectToWiFi();
  void connectToWebSocket();
  void idle();
  void pollWebSocket();

 public:
  void handleWebSocketEvent(websockets::WebsocketsEvent event, String data);
  void handleWebSocketMessage(websockets::WebsocketsMessage message);
  Device();
  void loop();
};

#endif  // DEVICE_H
