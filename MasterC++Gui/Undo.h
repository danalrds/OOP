#pragma once
#pragma once
#pragma once
#include "Repository.h"
#include <memory>

class Action {
public:
	virtual void doundo() = 0;
	virtual Tutorial getT()const { return Tutorial{}; };
	virtual std::string getType()const { return ""; };
};

class UndoAdd : public Action {
	Tutorial t;
	Repository& repo;
public:
	UndoAdd(Repository& rep, Tutorial t) :repo{ rep }, t{ t } {}
	void doundo() override {			
		int pos = repo.findByTitle_Presenter(t.getTitle());
		repo.deleteTutorial(pos);
	}
	Tutorial getT() const override{ return t; }
	std::string getType()const  override{ return "add"; };
};

class UndoRemove : public Action {
	Tutorial t;
	Repository& repo;
public:
	UndoRemove(Repository& rep, Tutorial t) :repo{ rep }, t{ t } {}
	void doundo() override {		
		repo.addTutorial(t);
	}
	Tutorial getT() const override { return t; }
	std::string getType()const  override { return "remove"; };
};

class UndoUpdate : public Action {
	Tutorial t;
	Repository& repo;
public:
	UndoUpdate(Repository& rep, Tutorial t) :repo{ rep }, t{ t } {}
	void doundo() override {
		int pos= repo.findByTitle_Presenter(t.getTitle());
		repo.deleteTutorial(pos);
		repo.addTutorial(t);
	}
	Tutorial getT() const { return t; }
	std::string getType()const  override { return "update"; };
};
/////////////////////          REDO  //////////////////////////////////
class RedoAdd : public Action {
	Tutorial t;
	Repository& repo;
public:
	RedoAdd(Repository& rep, Tutorial t) :repo{ rep }, t{ t } {}
	void doundo() override {
		int pos = repo.findByTitle_Presenter(t.getTitle());
		repo.addTutorial(t);
	}
	Tutorial getT() const override { return t; }
	std::string getType()const  override { return "add"; };
};

class RedoRemove : public Action {
	Tutorial t;
	Repository& repo;
public:
	RedoRemove(Repository& rep, Tutorial t) :repo{ rep }, t{ t } {}
	void doundo() override {
		int pos = repo.findByTitle_Presenter(t.getTitle());
		repo.deleteTutorial(pos);
	}
	Tutorial getT() const override { return t; }
	std::string getType()const  override { return "remove"; };
};

class RedoUpdate : public Action {
	Tutorial t;
	Repository& repo;
public:
	RedoUpdate(Repository& rep, Tutorial t) :repo{ rep }, t{ t } {}
	void doundo() override {
		int pos = repo.findByTitle_Presenter(t.getTitle());
		repo.deleteTutorial(pos);
		repo.addTutorial(t);
	}
	Tutorial getT() const override { return t; }
	std::string getType()const  override { return "update"; };
};