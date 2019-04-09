#pragma once
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include <string>
class Song
{
private:
	int id;
	std::string title ;   
	std::string artist;
	int duration;   //>0
	double heavy; ///[0.100]
public:
	Song();
	~Song();
	Song(const int id, const std::string& title, const std::string& artist, const int duration, const double heavy);
	int getId() const { return id; }
 	std::string getTitle() const { return title; }	
	std::string getArtist() const { return artist; }
	int getDuration() const { return duration; }
	double getHeavy() const { return heavy; }
	
};
