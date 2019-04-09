#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
class Car
{
private:
	std::string name;
	int price;
public:
	Car(std::string name, int price) : name{ name }, price{ price } {}
	~Car() {};
	std::string getName() { return name; }
	int getPrice() { return price; }
	friend std::ostream& operator<<(std::ostream& os, Car& c)
	{
		os <<c.name << " " <<c.price;
		return os;
	}
	bool operator>(Car& c)
	{
		return this->getPrice() > c.getPrice();
	}
};

//template <class T, class U>

template<typename T, typename U>
class Adder
{
private:
	std::vector<std::pair<T, U>> list;
public:
	Adder(T t, U u) 
	{	
		this->list.push_back(std::make_pair(t, u));
	}
	

	void add(T t ,U u)
	{

		this->list.push_back(std::make_pair(t, u));
	}

	void printReversed()
	{
		for (int i=this->list.size()-1;i>=0;i--)
		{
			std::cout << this->list[i].first << endl;
			std::cout << this->list[i].second << endl;
		}
	}
	void print()
	{
		for (int i=0; i<this->list.size(); i++)
		{
			std::cout << this->list[i].first << " ";
			std::cout << this->list[i].second << endl;
		}
	}
	void sortByFirst()
	{
		sort(this->list.begin(), this->list.end(), [](pair<T, U> a, pair<T, U> b) {return a.first >b .first; });
	}
	void sortBySecond()
	{
		sort(this->list.begin(), this->list.end(), [](pair<T, U> a, pair<T, U> b) {return a.second >b.second; });
	}
};