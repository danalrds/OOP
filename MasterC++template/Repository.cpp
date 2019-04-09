#include "Repository.h"
#include <string>

using namespace std;

void Repository::addTutorial(const Tutorial& s)
{
	this->tutorials.add(s);
}


void Repository::deleteTutorial(const int pos)
{
	this->tutorials.remove(pos);
		
	
}

void Repository::updateTutorial(const int pos, const Tutorial& newt)
{
	this->tutorials.update(pos, newt);
}

int Repository::findByTitle_Presenter(const std::string& title, const std::string& presenter )
{
	//cout << title << endl;
	Tutorial* tutorialsInDynamicVector = this->tutorials.getAllElems();
	for (int i = 0; i < this->tutorials.getSize(); i++)
	{			
		Tutorial s = tutorialsInDynamicVector[i];
		if (s.getTitle() == title && s.getPresenter() == presenter)
			return i;
	}

	return -1;
}
Tutorial Repository::find_Obj_ByTitle_Presenter(const std::string& title, const std::string& presenter)
{
	Tutorial* tutorialsInDynamicVector = this->tutorials.getAllElems();	

	for (int i = 0; i < this->tutorials.getSize(); i++)
	{
		Tutorial s = tutorialsInDynamicVector[i];
		if (s.getTitle() == title && s.getPresenter() == presenter)
			return s;
	}

	return Tutorial{};
}