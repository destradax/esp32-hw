#include "web_socket.h"

#include <Arduino.h>
#include <ArduinoWebsockets.h>

namespace web_socket {

websockets::WebsocketsClient connectToWebSocket(
    const char* host, const int port, const char* path,
    websockets::PartialMessageCallback messageCallback,
    websockets::PartialEventCallback eventCallback) {
  Serial.printf("Connecting to web socket at %s:%d%s\n", host, port, path);

  websockets::WebsocketsClient client;

  // TODO check if this is needed
  client.setInsecure();

  // run callback when messages are received
  client.onMessage(messageCallback);

  // run callback when events are occuring
  client.onEvent(eventCallback);

  // Connect to server
  client.connect(host, port, path);

  return client;
}

}  // namespace web_socket