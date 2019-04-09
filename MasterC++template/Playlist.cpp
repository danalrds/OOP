#include "Playlist.h"
#include <string>

using namespace std;

void PlayList::add(const Tutorial& t)
{
	this->playlist.add(t);
}

void PlayList::deleteTutorial(const int pos)
{
	this->playlist.remove(pos);
}

Tutorial PlayList::getCurrentTutorial()
{
	if (this->current == this->playlist.getSize())
		this->current = 0;
	Tutorial* elems = this->playlist.getAllElems();
	if (elems != NULL)
		return elems[this->current];
}

void PlayList::play()
{
	if (this->playlist.getSize() == 0)
		return;
	this->current = 0;
	Tutorial s = this->getCurrentTutorial();
	Duration d = s.getDuration();
	cout << "Now playing: " << s.getTitle() << " - " << s.getPresenter() << endl;
	s.play();
}

void PlayList::next()
{
	if (this->playlist.getSize() == 0)
		return;
	this->current++;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

bool PlayList::isEmpty()
{
	return this->playlist.getSize() == 0;
}


int PlayList::findByTitle_Presenter(const std::string& title, const std::string& presenter)
{
	Tutorial* tutorialsInDynamicVector = this->playlist.getAllElems();
	
	for (int i = 0; i < this->playlist.getSize(); i++)
	{
		Tutorial s = tutorialsInDynamicVector[i];
		if (s.getTitle() == title && s.getPresenter() == presenter)
			return i;
	}

	return -1;
}