#pragma once
#include "Repository.h"
#include "Playlist.h"

class Controller
{
private:
	Repository repo;	
	PlayList repoplay;
public:
	Controller(const Repository& r) : repo{ r } {}
	Controller(const PlayList& r) : repoplay{ r } {}

	Repository getRepo() const { return repo; }	
	PlayList getPlaylist() const { return repoplay; }

	// Adds a tutorial with the given data to the song repository.
	int addTutorialToRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link);

	int deleteTutorialRepository(const std::string& title, const std::string& presenter);
	int updateTutorialRepository(const std::string& title, const std::string& presenter, double minutes, double seconds, const int nrLikes, const std::string& link);
	void tests();
	int addTutorialToPlay(Tutorial t);
	int deleteTutorialPlaylist(const std::string& title, const std::string& presenter);
	void toPlayByPresenter(const std::string& presenter);
	void startPlaylist();
	void nextPlaylist();
		
};
