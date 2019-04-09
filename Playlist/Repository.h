#pragma once
#include "Song.h"

class Repository
{
private:
	std::vector<Song> songs;
public:
	Repository() {}
	void add(const Song& song);	
	std::vector<Song> getSongs() const { return songs; }
	int find(const int id);
};