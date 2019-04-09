#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class Commercial
{
private:
	std::string name;
	std::string link;
	int duration;
public:
	Commercial();
	~Commercial();
	Commercial(const std::string& name, const std::string& link, const int duration);
	
	std::string getName() const { return name; }
	std::string getLink() const { return link; }
	int getDuration() const { return duration; }
	void play();
};

