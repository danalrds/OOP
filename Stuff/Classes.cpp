#include "Classes.h"
#include <sstream>
#include <time.h>
void Telephone::send(std::string message) const
{
	srand(time(NULL));
	int r = rand() % 10;
	if (r != 2)
		throw std::exception("Busy!");
	std::cout << "dialing " << this->number << endl;
}
SMS::SMS(std::string number) : Telephone{ number }
{

}

Fax::Fax(std::string number) : Telephone{ number }
{

}

void Fax::send(std::string number) const
{
	Telephone::send(" ");
	cout << "sending Fax";
}

void SMS::send(std::string number) const
{
	Telephone::send(" ");
	cout << "sending SMS";
}


void Failover::send(std::string message) const
{
	try
	{
		this->ch1->send(message);
	}
	catch (std::exception& e)
	{
		this->ch2->send(message);
	}
}

void Contact::sendAlarm(std::string message)
{
	int ok = 0;
	while (ok == 0)
	{
		try
		{
			this->c1->send(message);
			ok = 1;
		}
		catch (std::exception& e)
		{
			try
			{
				this->c2->send(message);
				ok = 1;
			}
			catch (std::exception& e)
			{
				try
				{
					this->c3->send(message);
					ok = 1;
				}
				catch (std::exception& e)
				{
				}
			}
		}
	}
}