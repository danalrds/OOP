#include "Playlist.h"
#include "RepoExceptions.h"
#include <fstream>
#include <string>


using namespace std;

using namespace std;
PlayList::PlayList(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}


void PlayList::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Tutorial s;
	while (file >> s)
		this->playlist.push_back(s);

	file.close();
}

void PlayList::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->playlist)
	{
		file << s;
	}

	file.close();
}



void PlayList::add(const Tutorial& t)
{	
	int pos = this->findByTitle_Presenter(t.getTitle(), t.getPresenter());
	if (pos != -1)
		throw DuplicateException();
	this->playlist.push_back(t);
	this->writeToFile();
}

void PlayList::deleteTutorial(const int pos)
{
	if (pos == -1)
		throw InexistException();
	this->playlist.erase(this->playlist.begin() + pos);	
	this->writeToFile();
}

Tutorial PlayList::getCurrentTutorial()
{
	if (this->current == this->playlist.size())
		this->current = 0;
	std::vector<Tutorial> lista = this->getTutorials();
	if (lista.size() != 0)
		return lista[this->current];
	return Tutorial{};
}

void PlayList::play()
{
	if (this->playlist.size() == 0)
		return;
	this->current = 0;
	Tutorial s = this->getCurrentTutorial();
	Duration d = s.getDuration();
	cout << "Now playing: " << s.getTitle() << " - " << s.getPresenter() << endl;
	s.play();
}

void PlayList::next()
{
	if (this->playlist.size() == 0)
		return;
	this->current++;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

bool PlayList::isEmpty()
{
	return this->playlist.size() == 0;
}


int PlayList::findByTitle_Presenter(const std::string& title, const std::string& presenter)
{	
	std::vector<Tutorial> lista = this->getTutorials();
	for (int i = 0; i < this->playlist.size(); i++)
	{
		Tutorial s = lista[i];
		if (s.getTitle() == title && s.getPresenter() == presenter)
			return i;
	}

	return -1;
}