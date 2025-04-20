#ifndef LIGHTBULB
#define LIGHTBULB

#include <WebSocketsClient.h>

class Lightbulb {
 public:
  void processCommand(uint8_t* payload);

  void webSocketEvent(WStype_t type, uint8_t* payload, size_t length);
};

#endif