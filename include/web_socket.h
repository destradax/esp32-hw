#ifndef WEB_SOCKET_H
#define WEB_SOCKET_H

#include <ArduinoWebsockets.h>

namespace web_socket {

websockets::WebsocketsClient connectToWebSocket(
    const char* host, const int port, const char* path,
    websockets::PartialMessageCallback messageCallback,
    websockets::PartialEventCallback eventCallback);

}  // namespace web_socket

#endif
