#pragma once
#include"Observer.h"
#include"Repo.h"
class Controller :public Subject
{
	Repo&repo;
public:
	Controller(Repo&repo) :repo(repo) {}
	void addIssue(std::string desc, std::string status, std::string reporter, std::string solver)
	{
		Issue is{ desc,status,reporter,solver };		
		this->repo.addI(is);
		this->notify();
	}

	void removeIssue(std::string desc)
	{
		int pos = find(desc);
		this->repo.remove(pos);
		this->notify();
	}
	void updateStatus(std::string desc, std::string name)
	{
		int pos = find(desc);
		this->repo.update(pos,name);
		this->notify();
	}
	~Controller() {}
	std::vector<User> getU() const { return repo.getU(); }
	std::vector<Issue> getI() const { return repo.getI(); }
	int find(std::string desc)
	{
		int pos = 0;
		for (auto is:this->getI())
		{
			if (is.getDesc() == desc)
				return pos;
			pos = pos + 1;
		}
		return -1;
	}
};

