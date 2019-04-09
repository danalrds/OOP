#include "Controller.h"
#include "File.h"
using namespace std;

void Controller::addTutorialToRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link)
{
	Tutorial s{title, presenter,  Duration{ minutes, seconds }, nrLikes, link };
	this->validator.validate(s);
	this->repo.addTutorial(s);		
	
}

void Controller::deleteTutorialRepository(const std::string& title, const std::string& presenter)
{
	int pos = this->getRepo().findByTitle_Presenter(title, presenter);
	this->repo.deleteTutorial(pos);
}
void Controller::updateTutorialRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link)
{
	int pos = this->repo.findByTitle_Presenter(title, presenter);
	Tutorial newt{ title, presenter,  Duration{ minutes, seconds }, nrLikes, link };	
	this->repo.updateTutorial(pos, newt);
}
//PLAYLIST OPERATIONS

void Controller::addTutorialToPlay(Tutorial t)
{
	this->validator.validate(t);
	this->repoplay->add(t);
}

void Controller::toPlayByPresenter(const std::string& presenter)
{
	// get all the tutorials from the repository
	std::vector<Tutorial> v = this->repo.getTutorials();	
	for (int i = 0; i < v.size(); i++)
	{
		Tutorial s =v[i];
		if (s.getPresenter() == presenter)
			this->repoplay->add(s);
	}	
}

void Controller::deleteTutorialPlaylist (const std::string& title, const std::string& presenter)
{
	int pos = this->getPlaylist()->findByTitle_Presenter(title, presenter);
	this->repoplay->deleteTutorial(pos);	
}


void Controller::startPlaylist()
{
	this->repoplay->play();
}

void Controller::nextPlaylist()
{
	this->repoplay->next();
}

void Controller::savePlaylist()
{
	if (this->repoplay == nullptr)
		return;

	this->repoplay->writeToFile();
}

void Controller::openPlaylist() const
{
	if (this->repoplay == nullptr)
		return;

	this->repoplay->displayPlaylist();
}


