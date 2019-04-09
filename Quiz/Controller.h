#pragma once
#include"Observer.h"
#include"Repo.h"
class Controller :public Subject
{
	Repo&repo;
public:
	Controller(Repo&r) :repo(r) {};
	void addQuest(int id, std::string quest, std::string answer, int score)
	{
		//adds a new question to the repository of questions
		//if it is already there this will throw an exception
		Question q{ id, quest, answer, score };
		this->repo.add(q);
		this->notify();
	}
	void updateScore(std::string name, int score)
	{
		//updateScore calls the methof from the repo  update whicj will increase the score of the participant with
		//the given name to the new score
		this->repo.update(name, score);
	}
	int findPart(std::string name)
	{
		return this->repo.findPar(name);
	}
	
	~Controller() {}
	std::vector<Question> getQ() const { return repo.getQ(); }
	std::vector<Participant> getP() const { return repo.getP(); }
	int findP(std::string name) { return this->repo.findPar(name); }
	
};

