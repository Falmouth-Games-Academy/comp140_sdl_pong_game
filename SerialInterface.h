#pragma once

#include <serial\serial.h>
#include <string>

using std::string;

class SerialInterface
{
public:
	SerialInterface();
	~SerialInterface();

	void send(string msg);
	void getnewPositions();

	int getPosition1() { return pos1; };
	int getPosition2() { return pos2; };

	void close();

private:
	serial::Serial* mySerial;
	bool connected = false;

	int pos1 = 0;
	int pos2 = 0;
};
