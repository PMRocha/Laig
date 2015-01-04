#ifndef CONN_H
#define CONN_H

#include <stdio.h>
#include <iostream>
#include "winsock2.h"

#define IPADDRESS "127.0.0.1"
#define PORT 60070

class Conn {
private:
	SOCKET m_socket;
public:
	bool socketConnect();
	void sendData(char *s, int len);
	void receiveData(char *ans);
	void quit();
}

#endif