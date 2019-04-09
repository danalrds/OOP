#include "WritingSession.h"
#include<algorithm>
std::vector<Idea> WritingSession::getIdeas()
{
	std::vector<Idea> res;

	res = this->control.getIdeas();
	std::sort(res.begin(), res.end(), [](Idea a, Idea b) {return a < b; });
	return res;
}

void WritingSession::acceptIdea(std::string description, int act)
{
	this->control.updateIdea(description, act);
	this->notify();
}

WritingSession::~WritingSession()
{
}
