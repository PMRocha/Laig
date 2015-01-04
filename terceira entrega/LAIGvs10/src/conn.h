#ifndef CONN_H
#define CONN_H

#include <stdio.h>
#include "winsock2.h"

#define IPADDRESS "127.0.0.1"
#define PORT 60070

SOCKET m_socket;

bool socketConnect();

#endif