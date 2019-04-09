#include "Controller.h"



void Controller::addIdea(std::string description, std::string status, std::string creator, int act)
{
	if (act < 1 || act > 3)throw std::exception("invalid act");
	Idea d(description, status, creator, act);
	this->repo.addIdea(d);
}

void Controller::updateIdea(std::string desc, int act)
{
	this->repo.updateStatuse(desc, act);
}

bool Controller::hasAccepted(std::string name)
{
	for (auto d : this->getIdeas()) {
		if (d.getCreator() == name) {
			if (d.getStatus() == "accepted")return true;
		}
	}
	return false;
}

Controller::~Controller()
{
}
