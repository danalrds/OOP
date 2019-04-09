#include "Repo.h"
#include <fstream>
using namespace std;
Repo::Repo()
{
	this->readFromFileP();
	this->readFromFileQ();
}
void Repo::addQ(Question q)
{
	this->questions.push_back(q);
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
