#pragma once
#include "Tutorial.h"

class PlayList
{
private:
	std::vector<Tutorial> playlist;
	int current = 0;

public:
	PlayList();

	// Adds a tutorial to the playlist.
	void add(const Tutorial& tutorial);
	void deleteTutorial(const int pos);
	// Returns the tutorial that is currently playing.
	Tutorial getCurrentTutorial();
	int findByTitle_Presenter(const std::string& title);


	// Starts the playlist - plays the first tutorial.
	void play();

	// Plays the next tutorial in the playlist.
	void next();

	// Checks if the playlist is empty.
	bool isEmpty();
	Tutorial find_Obj_ByTitle_Presenter(const std::string& title);
	std::vector<Tutorial> getTutorials() const { return playlist; }
	virtual ~PlayList() {}

};


