#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>

//int Tutorial::objectCount = 0;
Tutorial::Tutorial() {
	//Tutorial::objectCount++;
	this->title = "";
	this->presenter = "";
	this->duration =Duration() ;
	this->nrLikes = 0;
	this->link = "";
	
}

Tutorial::~Tutorial()
{
	//objectCount--;
}



Tutorial::Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const int nrLikes, const std::string& link)
{
	//Tutorial::objectCount++;
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->nrLikes = nrLikes;
	this->link = link;
}

void Tutorial::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}


