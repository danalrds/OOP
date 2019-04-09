#pragma once
#include"Writer.h"
#include"Idea.h"
#include<fstream>
class Repository
{
	std::vector<Idea> ideas;
	std::vector<Writer> writers;
public:
	Repository();
	void readIdeasFromFile(std::string fname);
	void readWitersFromFile(std::string fname);
	/*add new idea to repository
	input-d, Idea object, to be added
	raise std exception if the an idea with the given decription and act alreay exist*/
	void addIdea(Idea d);
	std::vector<Idea> getIdeas() { return this->ideas; }
	std::vector<Writer> getWriters() { return this->writers; }
	/*updates the status of an idea
	input-description-string and int-act, the neccessary data for uniquely identifying an idea
	output-no output, the method changes the status of the idea, in case it does not find it, does nothing*/
	void updateStatuse(std::string description, int act);
	void updateDescription(std::string original, int act, std::string n);
	~Repository();
};

