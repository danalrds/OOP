#pragma once
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Activity
{
private:
	std::string act;
	std::string time;
public:
	Activity(std::string act, std::string time) : act{ act }, time{ time } {}
	~Activity() {}
	std::string getAct() const { return this->act; }
	std::string getTime() const {return this->time; }
	friend ostream& operator<<(ostream& os, const Activity& a);
};

ostream& operator<<(ostream& os, const Activity& a)
{
	os <<"Activity "<<a.act <<" will take place at "<< a.getTime();
	return os;
}

template  <typename  T>
class ToDo
{
private:
	std::vector<T> todo;
public:
	ToDo() {}
	~ToDo() {}
	ToDo<T>& operator +=(T& t);
	void reversePrint(ostream& stream);
	auto begin();
	auto end();
};
 
template < typename   T>
ToDo<T>& ToDo<T>::operator +=(T& t)
{
	
	this->todo.insert(this->todo.begin(),1,t);
	return *this;
}

template <typename T>
auto ToDo<T>::begin()
{
	return this->todo.begin();
}

template <typename T>
auto ToDo<T>::end()
{
	return this->todo.end();
}

template <typename T>
void ToDo<T>::reversePrint(ostream& stream)
{
	for (int i = this->todo.size() - 1; i >= 0; i--)
		stream << this->todo[i] << "\n";
}

