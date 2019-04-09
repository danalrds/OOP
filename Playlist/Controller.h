#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;
public:	
	Controller(const Repository& r) : repo(r) {}
	Repository getRepo() const { return repo; }
	void addSong(const Song& song);	
	void list(std::vector<Song> lista);
	std::vector<Song> make(const std::string& artist, const int duration);
	std::vector<Song> Mix(const int duration);
};