#pragma once
#include "Tutorial.h"
#include "Dyn.h"

class Repository
{
private:
	DynamicVector<Tutorial> tutorials;

public:
	
	Repository() {}

	/*
	Adds a tutorial to the repository.
	Input: s - Tutorial.
	Output: the tutorial is added to the repository.
	*/
	void addTutorial(const Tutorial& s);
	void deleteTutorial(const int pos);
	void updateTutorial(const int pos, const Tutorial& newt);	
	int findPosition(Tutorial t);
	int findByTitle_Presenter(const std::string& title, const std::string& presenter);
	Tutorial find_Obj_ByTitle_Presenter(const std::string& title, const std::string& presenter);

	DynamicVector<Tutorial> getTutorials() const { return tutorials; }
}; 
