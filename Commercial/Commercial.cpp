#include "Commercial.h"
#include <Windows.h>
#include <shellapi.h>
Commercial::Commercial()
{
	this->name = "";
	this->link = "";
	this->duration = 0;
}

Commercial::~Commercial()
{}

Commercial::Commercial(const std::string& name, const std::string& link, const int duration)
{
	this->name = name;
	this->link = link;
	this->duration = duration;
}

void Commercial::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}



