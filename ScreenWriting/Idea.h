#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
class Idea
{
	std::string description;
	std::string status;
	std::string creator;
	int act;
public:
	Idea() {}
	Idea(std::string d, std::string st, std::string cr, int act) :description(d), status(st), creator(cr), act(act) {}
	std::string getDescription() { return this->description; }
	std::string getStatus() { return this->status; }
	std::string getCreator() { return this->creator; }
	int getAct() { return this->act; }
	friend std::ostream&operator<<(std::ostream&os, Idea&d);
	friend std::istream&operator >> (std::istream&is, Idea&d);
	void setStatus(std::string status) { this->status = status; }
	bool operator==(Idea&d) { return this->description == d.description; }
	void setIdea(std::string idea) { this->description = description; }
	bool operator<(Idea&d);
	~Idea()
	{
	}
};

