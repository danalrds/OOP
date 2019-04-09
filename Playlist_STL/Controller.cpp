#include "Controller.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

void Controller::addSongToRepository(const std::string& artist, const std::string& title, double minutes, double seconds, const std::string& source)
{
	Song s{ artist, title, Duration{minutes, seconds}, source };
	this->repo.addSong(s);
}

void Controller::addSongToPlaylist(const Song& song)
{
	this->playList.add(song);
}

void Controller::addAllSongsByArtistToPlaylist(const std::string& artist)
{
	// get all the songs from the repository
	vector<Song> songs = this->repo.getSongs();
	
	// version 1
	/*for (vector<Song>::iterator it = songs.begin(); it != songs.end(); it++)
	{
		if (it->getArtist() == artist)
			this->playList.add(*it);
	}*/

	// version 2
	size_t songsByArtist = std::count_if(songs.begin(), songs.end(), [artist](Song s) {return s.getArtist() == artist; });
	vector<Song> result{ songsByArtist };
	std::copy_if(songs.begin(), songs.end(), result.begin(), [artist](Song s) {return s.getArtist() == artist; });
	for (auto it = result.begin(); it != result.end(); it++)
		this->playList.add(*it);
}

void Controller::startPlaylist()
{
	this->playList.play();
}

void Controller::nextSongPlaylist()
{
	this->playList.next();
}