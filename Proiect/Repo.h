#pragma once
#include "Classes.h"
#include <vector>
class Repo
{
private:
	std::vector<Question> questions;
	std::vector<Participant> participants;
public:
	Repo();
	~Repo() {};
	std::vector<Question> getQ() const { return this->questions; }
	std::vector<Participant> getP() const { return this->participants; }
	void addQ(Question q);
	void readFromFileQ();
	void readFromFileP();
	void printToFile();

};