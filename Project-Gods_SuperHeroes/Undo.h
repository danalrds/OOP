#pragma once
#include "Repo.h"
class Action {
public:
	virtual void doundo() = 0;
};

class Undo : public Action {
	Character* ch1;
	Character* ch2;
	Repo repo;
public:
	Undo(Repo repo, Character* ch1,Character* ch2) :repo{ repo }, ch1{ ch1 }, ch2 { ch2 } {}
	void doundo() override {
		this->repo.upt(ch1,ch2);
	}
};
