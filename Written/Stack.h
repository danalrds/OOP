#pragma once
#include <vector>
#include <string>
#include <stdlib.h>
template <typename T>
class Stack
{
private:
	std::vector<T> stack;
	int cap;
public:
	Stack(const int cap);
	~Stack();
	Stack<T>& operator +(const T& s);
	int getMaxCapacity() const { return this->cap; }
	// assignment operator for a stack
	T pop();
	Stack<T>& operator=(Stack<T>& v);
	std::vector<T> getStack() const { return this->stack; }
};

template <typename T>
Stack<T>::Stack(const int cap)
{
	this->cap = cap;
}
template <typename T>
Stack<T>::~Stack()
{}
template <typename T>
Stack<T>& Stack<T> ::operator+(const T& s)
{
	int size = this->stack.size();
	if (size < this->cap)
	{
		this->stack.push_back(s);
		return *this;
	}
	else
		throw std::exception("Stack is full!");
	
}
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>& v)
{
	if (this == &v)
		return *this;
	this->cap = v.cap;
	//std::vector<T> stack;
	this->stack = v.stack;
	return *this;
}
template <typename T>
T Stack<T>::pop()
{
	T a = stack.back();
	this->stack.pop_back();
	return a;
}


class Vector2D
{
private:
	double x;
	double y;

public:
	Vector2D();
	~Vector2D();
	Vector2D(double x, double y);
	Vector2D(const Vector2D& v);
	void add(Vector2D v);
	double getX() const { return this->x; }
	double getY() const { return this->y; }
};

