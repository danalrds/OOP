#pragma once
#include "File.h"
#include <string>

class HTMLPlaylist : public FilePlaylist
{
public:
	HTMLPlaylist(const std::string& filename) : FilePlaylist{ filename } {}
	void writeToFile() override;
	void displayPlaylist() const override;
};

