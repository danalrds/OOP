#pragma once
#pragma once
#include "Repo.h"
class Action {
public:
	virtual void doundo() = 0;
};

class UndoAdd : public Action {
	Water* water;
	Repo& repo;
public:
	UndoAdd(Repo& rep, Water* water) :repo{ rep }, water{ water } {}
	void doundo() override {
		repo.remove(water);
	}
};

class UndoRemove : public Action {
	Water* water;
	Repo& repo;
public:
	UndoRemove(Repo& rep, Water* water) :repo{ rep }, water{ water } {}
	void doundo() override {
		repo.add(water);
	}
};

class UndoUpdate : public Action {
	Water* water;
	Repo& repo;
public:
	UndoUpdate(Repo& rep, Water* water) :repo{ rep }, water{ water } {}
	void doundo() override {
		Water* w=repo.findW(water->getName());
		repo.remove(w);
		repo.add(water);
	}
};


