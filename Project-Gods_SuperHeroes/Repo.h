#pragma once
#include <vector>
#include <algorithm>
#include "Classes.h"
class Repo
{
private:
	std::vector<Character*> chars;
public:
	Repo();
	~Repo();
	void add(Character* ch);
	std::vector<Character*> getChars() const { return chars; }
	void update(const std::string conk, std::string targ);
	int find(std::string name);
	void upt(Character* ch1, Character* ch2);
};