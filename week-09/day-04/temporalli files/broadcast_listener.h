#ifndef BROADCAST_LISTENER_H_INCLUDED
#define BROADCAST_LISTENER_H_INCLUDED

#define BROADCAST_PORT 12345
#include "user.h"
#include <winsock2.h>

//public functions
void broadcast_server(totoro_user *users, WSADATA *wsaData);

#endif // BROADCAST_LISTENER_H_INCLUDED