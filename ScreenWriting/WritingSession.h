#pragma once
#include"Observer.h"
#include"Controller.h"
class WritingSession :public Subject
{
	Controller&control;
public:
	WritingSession(Controller&c) :control(c) {};
	void addIdea(std::string description, std::string status, std::string creator, int act) {
		this->control.addIdea(description, status, creator, act);
		this->notify();
	}
	std::vector<Idea>getIdeas();
	void acceptIdea(std::string description, int act);
	bool hasAccepted(std::string name) { return this->control.hasAccepted(name); }
	~WritingSession();
};

