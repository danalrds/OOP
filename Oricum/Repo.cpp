#include "Repo.h"
#include <fstream>
using namespace std;
Repo::Repo()
{
	this->readFromFileI();
	this->readFromFileU();
}
void Repo::printToFile()
{
	std::string filename = "issues.txt";
	ofstream file(filename);
	if (!file.is_open())
		throw std::exception("error");
	for (auto q : this->issues)
	{
		file << q;
	}
	file.close();
}
void Repo::addI(Issue is)
{
	this->issues.push_back(is);
}
void Repo::remove(int pos)
{
	Issue is = this->issues[pos];
	if (is.getStatus()=="closed")
		this->issues.erase(this->issues.begin() + pos);
}
void Repo::update(int pos,std::string name)
{
	this->issues[pos].setStatus("closed");
	this->issues[pos].setSolver(name);
}
void Repo::readFromFileU()
{

	std::string filename = "users.txt";
	ifstream file(filename);

	if (!file.is_open())
		throw std::exception("The file could not be opened!");

	User u;
	while (file >> u)
		this->users.push_back(u);

	file.close();
}


void Repo::readFromFileI()
{

	std::string filename = "issues.txt";
	ifstream file(filename);

	if (!file.is_open())
		throw std::exception("The file could not be opened!");

	Issue u;
	while (file >> u)
		this->issues.push_back(u);

	file.close();
}
