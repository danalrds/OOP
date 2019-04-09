#pragma once
#include "Tutorial.h"

class Repository
{
private:
	std::vector<Tutorial> tutorials;
	std::string filename;
public:

	Repository(const std::string& filename);

	/*
	Adds a tutorial to the repository.
	Input: s - Tutorial.
	Output: the tutorial is added to the repository.
	*/
	void addTutorial(const Tutorial& s);
	void deleteTutorial(const int pos);
	void updateTutorial(const int pos, const Tutorial& newt);
	int findByTitle_Presenter(const std::string& title);
	Tutorial find_Obj_ByTitle_Presenter(const std::string& title);

	std::vector<Tutorial> getTutorials() const { return tutorials; }
private:
	void readFromFile();
	void writeToFile();
};

