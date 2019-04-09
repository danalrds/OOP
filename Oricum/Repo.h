#pragma once
#include "Classes.h"
#include <vector>
#include <algorithm>
class Repo
{
private:
	std::vector<User> users;
	std::vector<Issue> issues;
public:
	Repo();
	~Repo() {};
	std::vector<User> getU() const { return users; }
	std::vector<Issue> getI() const { return issues; }
	void readFromFileU();
	void readFromFileI();
	void printToFile();
	void addI(Issue i);
	void remove(int pos);
	void update(int pos,std::string name);
};