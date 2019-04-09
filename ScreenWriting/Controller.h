#pragma once
#include"Repository.h"
class Controller
{
	Repository&repo;
public:
	Controller(Repository&r) :repo(r) {}
	void addIdea(std::string description, std::string status, std::string creator, int act);
	std::vector<Idea> getIdeas() { return this->repo.getIdeas(); }
	void readIdeasFromFile(std::string fname) { this->repo.readIdeasFromFile(fname); }
	void readWritersFromFile(std::string fname) { this->repo.readWitersFromFile(fname); }
	std::vector<Writer>getWriters() { return this->repo.getWriters(); }
	/*updates the status of the idea with the given description and act
	input-description and act, the data neccessary for identifying an idea
	no output, no exceptions*/
	void updateIdea(std::string desc, int act);
	bool hasAccepted(std::string name);
	~Controller();
};

