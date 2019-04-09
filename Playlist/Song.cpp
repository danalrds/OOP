#include "Song.h"

Song::Song()
{
	this->id = 0;
	this->title = "";
	this->artist = "";
	this-> duration= 0;
	this->heavy = 0;
}

Song::~Song()
{}

Song::Song(const int id, const std::string& title, const std::string& artist, const int duration, const double heavy)
{
	this->id = id;
	this->title = title;
	this->artist = artist;
	this->duration = duration;
	this->heavy = heavy;
}


