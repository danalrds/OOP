#pragma once

#include"Observer.h"
#include"Repo.h"
class Controller :public Subject
{
	Repo&repo;
public:
	Controller(Repo&repo) :repo(repo) {}
	void addQuest(int id, std::string text, std::string correct, int score)
	{
		Question q{id, text, correct, score };
		this->repo.addQ(q);
		this->notify();
	}

	~Controller() {}
	std::vector<Question> getQ() const { return repo.getQ(); }
	std::vector<Participant> getP() const { return repo.getP(); }
	
};



