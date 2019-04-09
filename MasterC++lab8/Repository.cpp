#include "Repository.h"
#include "RepoExceptions.h"
#include <fstream>
#include <string>

using namespace std;
Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}


void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Tutorial s;
	while (file >> s)
		this->tutorials.push_back(s);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->tutorials)
	{
		file << s;
	}

	file.close();
}

void Repository::addTutorial(const Tutorial& s)
{
	int pos = this->findByTitle_Presenter(s.getTitle(),s.getPresenter());
	if (pos!= -1)
		throw DuplicateException();
	this->tutorials.push_back(s);
	this->writeToFile();
}


void Repository::deleteTutorial(const int pos)
{
	if (pos==-1)
		throw InexistException();
	this->tutorials.erase(this->tutorials.begin()+pos);	
	this->writeToFile();
}

void Repository::updateTutorial(const int pos, const Tutorial& newt)
{
	if (pos == -1)
	{
		throw InexistException();
	}
	this->tutorials[pos] = newt;
	this->writeToFile();
}

int Repository::findByTitle_Presenter(const std::string& title, const std::string& presenter )
{
	//cout << title << endl;
	std::vector<Tutorial> lista = this->getTutorials();
	for (int i = 0; i < lista.size(); i++)
	{			
		Tutorial s = lista[i];
		if (s.getTitle() == title && s.getPresenter() == presenter)
			return i;
	}

	return -1;
}
Tutorial Repository::find_Obj_ByTitle_Presenter(const std::string& title, const std::string& presenter)
{
	std::vector<Tutorial> lista = this->getTutorials();

	for (int i = 0; i < lista.size(); i++)
	{
		Tutorial s = lista[i];
		if (s.getTitle() == title && s.getPresenter() == presenter)
			return s;
	}

	return Tutorial{};
}