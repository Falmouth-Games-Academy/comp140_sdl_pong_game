#pragma once
#include <serial\serial.h>
#include <string>

class SerialInterface
{
public:
	SerialInterface();
	~SerialInterface();

	void send(std::string message);
	void getPositions();

	void close();

	int getPot1()
	{
		return pot1;
	};

	int getPot2()
	{
		return pot2;
	};

private:
	serial::Serial* mySerial;
	bool connected = false;

	//Potentiometers
	int pot1 = 0;
	int pot2 = 0;

protected:
};

