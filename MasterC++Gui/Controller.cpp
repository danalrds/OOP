#include "Controller.h"
#include "File.h"
using namespace std;

void Controller::addTutorialToRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link)
{
	Tutorial s{ title, presenter,  Duration{ minutes, seconds }, nrLikes, link };
	this->validator.validate(s);
	undoActions.push_back(std::make_unique<UndoAdd>(repo, s));
	this->repo.addTutorial(s);

}

void Controller::deleteTutorialRepository(const std::string& title, const std::string& presenter)
{
	int pos = this->getRepo().findByTitle_Presenter(title);
	Tutorial w = this->repo.find_Obj_ByTitle_Presenter(title);
	undoActions.push_back(std::make_unique<UndoRemove>(repo, w));
	this->repo.deleteTutorial(pos);
}
void Controller::updateTutorialRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link)
{
	int pos = this->repo.findByTitle_Presenter(title);
	Tutorial w = this->repo.find_Obj_ByTitle_Presenter(title);
	Tutorial newt{ title, presenter,  Duration{ minutes, seconds }, nrLikes, link };
	undoActions.push_back(std::make_unique<UndoUpdate>(repo, w));
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
		Tutorial s = v[i];
		if (s.getPresenter() == presenter)
			this->repoplay->add(s);
	}
}

void Controller::deleteTutorialPlaylist(const std::string& title, const std::string& presenter)
{
	int pos = this->getPlaylist()->findByTitle_Presenter(title);
	this->repoplay->deleteTutorial(pos);
}

void Controller::undo()
{
	if (undoActions.empty() == false)
	{			
		Action* a = undoActions.back().get();
		Tutorial tt = a->getT();
		std::string type = a->getType();
		if (type=="add")
			redoActions.push_back(std::make_unique<RedoAdd>(repo, tt));
		else if (type=="remove")
			redoActions.push_back(std::make_unique<RedoRemove>(repo, tt));
		else
			redoActions.push_back(std::make_unique<RedoUpdate>(repo, tt));
		undoActions.back()->doundo();
		undoActions.pop_back();
	}	
}
void Controller::redo()
{
	if (redoActions.empty() == false)
	{
		Action* a = redoActions.back().get();
		Tutorial tt = a->getT();
		std::string type = a->getType();
		if (type == "add")
			undoActions.push_back(std::make_unique<UndoAdd>(repo, tt));
		else if (type == "remove")
			undoActions.push_back(std::make_unique<UndoRemove>(repo, tt));
		else
			undoActions.push_back(std::make_unique<UndoUpdate>(repo, tt));

		redoActions.back()->doundo();
		redoActions.pop_back();
	}
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


