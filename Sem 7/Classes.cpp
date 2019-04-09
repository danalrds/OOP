#include "Classes.h"
Observer::~Observer()
{}

Subject::Subject()
{}
Subject::~Subject()
{}
void Subject::registerO(Observer* obs)
{
	this->observers.push_back(obs);
}
void Subject::notify()
{
	for (auto o : observers)
		o->update();
}

void ChatSession::AddMessage(string user, string message)
{
	this->messages.push_back(std::pair<string, string>(user, message));
	this->notify();
}