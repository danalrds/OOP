#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Adder
{
private:
	std::vector<T> el;
public:
	std::vector<T> getEl() const { return this->el; }
	Adder(const T&t) { this->el.push_back(t); }
	~Adder() {}
	Adder<T>& operator+(const T& t)
	{
		this->el.push_back(t);
		return *this;
	}
	Adder<T>& operator ++()
	{
		T a = this->el.back();
		this->el.push_back(a);
		return *this;
	}
	Adder<T>& operator --()
	{
		if (this->el.size() == 0)
			throw std::runtime_error("No more values!");
		else
		{
			this->el.erase(this->el.begin() + this->el.size() - 1);
			return *this;
		}
	}
	T& sum()
	{
		T s = 0;
		for (auto t : this->el)
			s = s + t;
		return s;
	}
	void operator ()()
	{
		T a = this->el.back();
		this->el.push_back(a);

	}
	
};



class Ex1
{
public:
	Ex1() { cout << "Exception1"; }
	Ex1(const Ex1& ex) { cout << "Copy_ex1"; }
};
  
class Ex2 :public Ex1
{
public:
	Ex2() { cout << "Exception2"; }
	Ex2(const Ex2& ex) { cout << "Copy_exc2"; }
};

class E 
{ public:
	E() { std::cout << "E{}"; } 
	virtual ~E() { std::cout << "~E()"; }
};
class DE : public E
{ public: 
	static int n;
	DE() { n++; } 
};

int DE::n = 0;

int fct2(int x)
{
	if (x < 0)
	{
		throw E{};
		std::cout << "number less than 0" << std::endl;
	}
	else if (x == 0)

	{
		throw DE{};
		std::cout << "number equal to 0" << std::endl;
	}
	return x % 10;

}



class Person 
{ 
public: 
	Person() { std::cout << "Person{}"; } 
	virtual void print() = 0; 
	virtual ~Person() { std::cout << "~Person()"; } 
};
class Student : public Person
{
public:
	Student() { std::cout << "Student{}"; }
	void print() override { std::cout << "Student"; }
	 virtual~Student() { std::cout << "~Student()"; }
};



class B
{
public:
	B() { std::cout << "B{}"; }
	virtual void print() { std::cout << "B"; }
	virtual~B() { std::cout << "~B()"; }
};

class D : public B
{
public:
	D() { std::cout << "D{}"; }
	void print() override { std::cout << "D"; }
	virtual~D() {
		std::cout << "~D()";
	}
};