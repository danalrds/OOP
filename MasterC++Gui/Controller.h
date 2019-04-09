#pragma once
#include "Repository.h"
#include "File.h"
#include "Validator.h"
#include <memory>
#include "Undo.h"

class Controller
{
private:
	Repository repo;
	FilePlaylist* repoplay;
	Validator validator;
	std::vector<std::unique_ptr<Action>> undoActions;
	std::vector<std::unique_ptr<Action>> redoActions;
public:
	
	Controller(const Repository& r, FilePlaylist* p, Validator v) : repo{ r }, repoplay{ p }, validator{ v } {}

	Repository getRepo() const { return repo; }
	PlayList* getPlaylist() const { return repoplay; }

	// Adds a tutorial with the given data to the song repository.
	void addTutorialToRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link);

	void deleteTutorialRepository(const std::string& title, const std::string& presenter);
	void updateTutorialRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link);
	void addTutorialToPlay(Tutorial t);
	void deleteTutorialPlaylist(const std::string& title, const std::string& presenter);
	void toPlayByPresenter(const std::string& presenter);
	void startPlaylist();
	void nextPlaylist();
	void savePlaylist();
	void undo();
	void redo();
	void openPlaylist() const;

};
