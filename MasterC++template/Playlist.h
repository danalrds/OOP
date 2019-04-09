#pragma once
#include "Dyn.h"
#include "Tutorial.h"

class PlayList
{
private:
	DynamicVector<Tutorial> playlist;
	int current =0;

public:
	PlayList() {}	

	// Adds a tutorial to the playlist.
	void add(const Tutorial& tutorial);
	void deleteTutorial(const int pos);
	// Returns the tutorial that is currently playing.
	Tutorial getCurrentTutorial();
	int findByTitle_Presenter(const std::string& title, const std::string& presenter);


	// Starts the playlist - plays the first tutorial.
	void play();

	// Plays the next tutorial in the playlist.
	void next();

	// Checks if the playlist is empty.
	bool isEmpty();
	DynamicVector<Tutorial> getTutorials() const { return playlist; }

};


