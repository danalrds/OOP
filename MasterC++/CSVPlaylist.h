#pragma once
#include "File.h"
#include <string>

class CSVPlaylist : public FilePlaylist
{
public:
	CSVPlaylist(const std::string& filename) : FilePlaylist{ filename } {}
	void writeToFile() override;	
	void displayPlaylist() const override;
};

