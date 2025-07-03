#include "device.h"

#include <ArduinoWebsockets.h>

#include "blink.h"
#include "credentials.h"
#include "web_socket.h"
#include "wifi.h"

Device::Device() {
  this->isConnectedToWiFi = false;
  this->isConnectedToWebSocket = false;
}

void Device::connectToWiFi() {
  this->isConnectedToWiFi = wifi::connectToWiFi(WIFI_SSID, WIFI_PASS_PHRASE);
}

void Device::connectToWebSocket() {
  this->webSocket = web_socket::connectToWebSocket(
      WEB_SOCKET_HOST, WEB_SOCKET_PORT, WEB_SOCKET_PATH,
      [this](websockets::WebsocketsMessage message) {
        this->handleWebSocketMessage(message);
      },
      [this](websockets::WebsocketsEvent event, String data) {
        this->handleWebSocketEvent(event, data);
      });
}

void Device::pollWebSocket() {
  bool hasNewMessages = this->webSocket.poll();
  if (!hasNewMessages) {
    return this->idle();
  }
}

void Device::handleWebSocketMessage(websockets::WebsocketsMessage message) {
  Serial.print("Device got a Message: ");
  Serial.println(message.data());
}

void Device::handleWebSocketEvent(websockets::WebsocketsEvent event,
                                  String data) {
  if (event == websockets::WebsocketsEvent::ConnectionOpened) {
    this->isConnectedToWebSocket = true;
  } else if (event == websockets::WebsocketsEvent::ConnectionClosed) {
    this->isConnectedToWebSocket = false;
  } else {
    Serial.println("Another event");
  }
}

void Device::idle() {
  Serial.println("Device idle");
  blinkSlow();
}

void Device::loop() {
  if (!this->isConnectedToWiFi) {
    Serial.println('not isConnectedToWiFi');
    return this->connectToWiFi();
  }

  if (!this->isConnectedToWebSocket) {
    Serial.println('not isConnectedToWebSocket');
    return this->connectToWebSocket();
  }

  return this->pollWebSocket();
}