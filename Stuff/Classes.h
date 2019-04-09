#pragma once
#include <vector>
#include <iostream>
using namespace std;


class Channel
{
public:
	virtual void send(std::string message)const = 0;
	virtual ~Channel() { cout << "channel\n"; }
};

class Telephone : public Channel
{
private:
	std::string number;
public:
	Telephone() {}
	Telephone(std::string number) : number{ number } {}
	std::string getNumber() { return number; }
	void send(std::string message) const override;
	~Telephone() { cout << "tele\n"; }
};

class SMS : public Telephone
{
public:
	SMS(std::string number);
	void send(std::string message) const override;
	~SMS() { cout << "sms\n"; }
};


class Fax : public Telephone
{
public:
	Fax(std::string number);
	void send(std::string message) const override;
	~Fax() { cout << "Fax\n"; }
};

class Failover : public Channel
{
private:
	Channel * ch1;
	Channel* ch2;
public:
	void send(std::string message)  const override;
	Failover(Channel* c1, Channel* c2) : ch1{ c1 }, ch2{ c2 } {}
	~Failover() { delete ch1; delete ch2; cout << "Failover\n"; }
};

class Contact
{
private:
	Channel * c1;
	Channel* c2;
	Channel* c3;
public:
	Contact(Channel* c1, Channel* c2, Channel* c3) : c1{ c1 }, c2{ c2 }, c3{ c3 } {}
	~Contact() { delete c1; delete c2; delete c3; cout << "contact\n"; }
	void sendAlarm(std::string message);
};