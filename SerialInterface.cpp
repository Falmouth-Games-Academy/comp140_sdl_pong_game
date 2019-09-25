#include "SerialInterface.h"

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
