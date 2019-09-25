#include "SerialInterface.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::exception;
using std::stoi;
using std::string;

SerialInterface::SerialInterface()
{
	vector <serial::PortInfo> devicesAvailable = serial::list_ports();

	vector <serial::PortInfo>::iterator iter = devicesAvailable.begin();

	while (iter != devicesAvailable.end())
	{
		serial::PortInfo device = *iter++; //Iterating port information about the device
		string port = device.port.c_str(); //show the devie as string

		try
		{
			Cereal = new serial::Serial(port, 115200, serial::Timeout::simpleTimeout(250));
			//if the connection is successful, contactmade
			if (Cereal->isOpen())
			{
				cout << "The connection has been made, on the port: " << port << '/n';
				contactmade = true;

				break;
			}
		}

	}
}

void SerialInterface::send(string msg)
{
	if (contactmade)
	{
		Cereal->write(msg);
	}
}

void SerialInterface::getnewPositions()
{
	if (contactmade)
	{
		Cereal->write("A"); //Write this if connection successfully

		string result = mySerial->readline();

		if (result.length() >= 9)
		{
			string sub1 = result.substr(0, 4);
			pot1 = std::stoi(sub1); //Responsible for pos1

			string sub2 = result.substr(5, 9);
			pot2 = std::stoi(sub2); //Responsible for pos2
		}
	}
}
