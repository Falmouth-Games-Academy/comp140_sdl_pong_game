#include "SerialInterface.h"

//#include "stdafx.h"
#include <iostream>

using std::cout;
using std::vector;
using std::exception;

const bool InStudio = true;
const std::string PORT_NO = "COM6";

SerialInterface::SerialInterface()
{
	if (!InStudio) 
	{
		//Store list of available ports in vector
		vector <serial::PortInfo> devicesFound = serial::list_ports();
		vector <serial::PortInfo>::iterator iter = devicesFound.begin();

		//Iterate over ports to try and establish a serial connection
		while (iter != devicesFound.end())
		{
			serial::PortInfo device = *iter++;
			std::string port = device.port.c_str();

			try
			{
				mySerial = new serial::Serial(port, 115200, serial::Timeout::simpleTimeout(250));
				if (mySerial->isOpen())
				{
					cout << "Connection Success: " << port << "\n";
					connected = true;

					break;
				}
			}

			catch (exception &e)
			{

			}
		}
	}

	//Use set port number for when other ports are open with other devices.
	else
	{
		try
		{
			mySerial = new serial::Serial(PORT_NO, 115200, serial::Timeout::simpleTimeout(250));
			if (mySerial->isOpen())
			{
				cout << "Connection Success: " << PORT_NO << "\n";
				connected = true;
			}
		}

		catch (exception &e)
		{

		}
	}
}

SerialInterface::~SerialInterface()
{
}

void SerialInterface::send(std::string message)
{
	if (connected)
	{
		mySerial->write(message);
	}
}

void SerialInterface::getPositions()
{
	if (connected)
	{
		mySerial->write("P");
		std::string result = mySerial->readline();

		//Divide string to get two values
		std::string sub1 = result.substr(0, 4);
		std::string sub2 = result.substr(5, 9);

		//Convert values to int
		if (sub1 != "")
		{
			pot1 = std::stoi(sub1);
		}

		if (sub2 != "")
		{
			pot2 = std::stoi(sub2);
		}

	}
}

void SerialInterface::close()
{
	mySerial->flush();
	mySerial->close();
}
