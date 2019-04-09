#include "Controller.h"


int Controller::addTutorialToRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link)
{
	Tutorial s{title, presenter,  Duration{ minutes, seconds }, nrLikes, link };
	int pos = this->repo.findByTitle_Presenter(title, presenter);
	if (pos == -1)
	{
		this->repo.addTutorial(s);
		return 1;
	}
	return -1;	
}

int Controller::deleteTutorialRepository(const std::string& title, const std::string& presenter)
{
	int pos = this->repo.findByTitle_Presenter(title, presenter);
	if (pos != -1)
	{			
		this->repo.deleteTutorial(pos);
		return 1;
	}
	return -1;
}
int Controller::updateTutorialRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link)
{
	int pos = this->repo.findByTitle_Presenter(title, presenter);
	Tutorial newt{ title, presenter,  Duration{ minutes, seconds }, nrLikes, link };
	
	if (pos != -1)
	{
		this->repo.updateTutorial(pos, newt);
		return 1;
	}
	return -1;
}
//PLAYLIST OPERATIONS

int Controller::addTutorialToPlay(Tutorial t)
{
	int pos = this->repoplay.findByTitle_Presenter(t.getTitle(), t.getPresenter());
	if (pos == -1)
	{
		this->repoplay.add(t);
		return 1;
	}
	return -1;
}

void Controller::toPlayByPresenter(const std::string& presenter)
{
	// get all the tutorials from the repository
	DynamicVector<Tutorial> v = this->repo.getTutorials();
	Tutorial* playlist = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++)
	{
		Tutorial s = playlist[i];
		if (s.getPresenter() == presenter)
			this->repoplay.add(s);
	}	
}

int Controller::deleteTutorialPlaylist (const std::string& title, const std::string& presenter)
{
	int pos = this->repoplay.findByTitle_Presenter(title, presenter);
	if (pos != -1)
	{
		this->repoplay.deleteTutorial(pos);
		return 1;
	}	
		return -1;
}


void Controller::startPlaylist()
{
	this->repoplay.play();
}

void Controller::nextPlaylist()
{
	this->repoplay.next();
}

