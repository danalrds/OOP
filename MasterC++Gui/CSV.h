#pragma once
#include "File.h"
#include <string>

class CSVPlaylist : public FilePlaylist
{
public:
	CSVPlaylist(const std::string& filename) : FilePlaylist{ filename } {}

	/*
	Writes the playlist to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the playlist using Microsof Excel.
	*/
	void displayPlaylist() const override;
};


