#pragma once
#include "Playlist.h"

class FilePlaylist : public PlayList
{
protected:
	std::string filename;

public:
	FilePlaylist(const std::string& filename);
	virtual ~FilePlaylist() {}

	virtual void writeToFile() = 0;
	virtual void displayPlaylist() const = 0;
};


