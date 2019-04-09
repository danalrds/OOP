#include "Playlist.h"
#include "RepoExceptions.h"
#include <fstream>
#include <string>
using namespace std;

PlayList::PlayList()
{
	this->current = 0;
}

void PlayList::add(const Tutorial& t)
{	
	int pos = this->findByTitle_Presenter(t.getTitle(), t.getPresenter());
	if (pos != -1)
		throw DuplicateException();
	this->playlist.push_back(t);
}

void PlayList::deleteTutorial(const int pos)
{
	if (pos == -1)
		throw InexistException();
	this->playlist.erase(this->playlist.begin() + pos);		
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