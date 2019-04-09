#include <vector>
#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include "Utils.h"

using namespace std;

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

istream & operator>>(istream & is, Tutorial & s)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) // make sure all the song data was valid
		return is;

	s.title = tokens[0];
	s.presenter = tokens[1];

	// get duration
	vector<string> durationTokens = tokenize(tokens[2], ':');
	if (durationTokens.size() != 2)
		return is;
	s.duration = Duration{ stod(durationTokens[0]), stod(durationTokens[1]) };

	s.nrLikes= stoi(tokens[3]);	
	s.link = tokens[4];

	return is;

}


ostream & operator<<(ostream& os, const Tutorial& s)
{
	os << s.title << "," << s.presenter << "," << s.duration.getMinutes() << ":" << s.duration.getSeconds() 
		<< "," << s.nrLikes << "," << s.link << "\n";
	return os;
}
