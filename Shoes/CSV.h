#pragma once
#include "Repo.h"
#include <vector>
#include <algorithm>

class CSV :public Repo
{
private:
	std::string filename;
public:
	CSV(const std::string& filename);
	void writeToFile() const override;
	void display() const override;
	~CSV();
};



