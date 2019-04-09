#pragma once
#include<vector>
class Observer
{
public:
	Observer() {};
	virtual void update() = 0;
	virtual~Observer() {};
};

class Subject {
	std::vector<Observer*> observers;
public:
	Subject() {}
	void refisterObserver(Observer*o) { this->observers.push_back(o); }
	void unregisterObserver(Observer*o) { this->observers.erase(std::find(this->observers.begin(), this->observers.end(), o)); }
	void notify() {
		for (auto o : this->observers) {
			o->update();
		}
	}

};