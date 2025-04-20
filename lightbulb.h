#ifndef LIGHTBULB_H
#define LIGHTBULB_H

#include <WebSocketsClient.h>

class Lightbulb {
 public:
  void processCommand(uint8_t* payload);

  void webSocketEvent(WStype_t type, uint8_t* payload, size_t length);
};

#endif