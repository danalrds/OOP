#pragma once
#include "Repo.h"
class Action {
public:
	virtual void doundo() = 0;
};

class UndoAdd : public Action {
	Offer* offer;
	Repo* repo;
public:
	UndoAdd(Repo* rep,  Offer* offer) :repo{ rep }, offer{ offer } {}
	void doundo() override {
		repo->remove(offer);
	}
};

class UndoRemove : public Action {
	Offer* offer;
	Repo* repo;
public:
	UndoRemove(Repo* rep, Offer* offer) :repo{ rep }, offer{ offer } {}
	void doundo() override {
		repo->add(offer);
	}
};


