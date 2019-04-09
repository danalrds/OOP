#include "Repo.h"
#include <fstream>
using namespace std;
int Repo::findPar(std::string name)
{
	int pos = 0;
	for (auto p : this->participants)
	{
		if (p.getName() == name)
			return pos;
		pos = pos + 1;
	}	
}

Repo::Repo()
{
	readFromFileQ();
	readFromFileP();
}
//updates the score of a participant that gave a good answer to  new one
//it receives a name and the score to be added at the current score
void Repo::update(std::string name, int score)
{
	int pos = this->findPar(name);
	this->participants[pos].setScore(score);
}
Repo::~Repo()
{}
//adds a new question to the questions list
//if the given id is allready there it throws an exceptin
void Repo::add(Question q)
{
	int pos = find(q.getId());
	if (pos == -1)
	{
		this->questions.push_back(q);
	}
	else
		throw std::exception("already in repo");

}

int Repo::find(int id)
{
	int pos = 0;
	for (auto q : this->questions)
	{
		if (q.getId() == id)
			return pos;
		pos = pos + 1;
	}
	return -1;
}
void Repo::printToFile()
{
	std::string filename = "questions.txt";
	ofstream file(filename);
	if (!file.is_open())
		throw std::exception("error");
	for (auto q : this->questions)
	{
		file << q;
	}
	file.close();
}

void Repo::readFromFileQ()
{

	std::string filename = "questions.txt";
	ifstream file(filename);

	if (!file.is_open())
		throw std::exception("The file could not be opened!");

	Question q;
	while (file >> q)
		this->questions.push_back(q);

	file.close();
}

void Repo::readFromFileP()
{

	std::string filename = "participants.txt";
	ifstream file(filename);

	if (!file.is_open())
		throw std::exception("The file could not be opened!");

	Participant p;
	while (file >> p)
		this->participants.push_back(p);

	file.close();
}

