#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer();
};

class Subject
{
private:
	std::vector<Observer*> observers;
public:
	Subject();
	~Subject();
	void registerO(Observer* obs);
	void notify();

};

class ChatSession: public Subject
{
private:
	vector< pair<string, string>> messages;
public:
	void AddMessage(string user, string message);
	std::vector<pair <string, string>> getMessages() { return messages; }
};