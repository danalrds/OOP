#include <string>
#include <stdlib.h>
#include "Stack.h"
#include <assert.h>
#include <iostream>
#include "ToDo.h"
#include <Windows.h>
#include "Classes.h"
#include <deque>

void testToDo()
{
	ToDo<Activity> todo{};
	Activity tiff{ "go to TIFF movie", "20:00" };
	todo += tiff;
	Activity project{ "present project assignment", "09.20" };
	todo += project;
	// iterates through the activities and prints them as follows:
	// Activity present project assignment will take place at 09.20.
	// Activity go to TIFF movie will take place at 20.00.
	for (auto a : todo)
		std::cout << a << '\n';
	// Prints the activities as follows:
	// Activity go to TIFF movie will take place at 20.00.
	// Activity present project assignment will take place at 09.20.
	todo.reversePrint(std::cout);
}
void test1()
{
	Vector2D v1{ 1, 1 };	// aggregate initialization
	Vector2D v2{ 3,4 };
	v1.add(v2);
	assert(v1.getX() == 4);
	assert(v1.getY() == 5);
	Vector2D v3{ v2 };
	assert(v3.getX() == 3);
	assert(v3.getY() == 4);
	Vector2D array[5]; //default constructor called 5 times

}
void testStack() 
{
	Stack<std::string> s{ 2 };
	assert(s.getMaxCapacity() == 2);
	try {
		s=s + "examination";
		s = s + "oop";
		s = s + "test";
		assert(s.getStack().back()=="oop");
	}
	catch (std::exception& e)
	{
		assert(strcmp(e.what(), "Stack is full!") == 0);
	}
	assert(s.pop() == "oop");
	assert(s.pop() == "examination");
}
void testDc()
{
		B* b[] = { new B{}, new D{} };
		b[0]->print(); 
		b[1]->print(); 
		delete b[0]; 
		delete b[1]; 
}
void testPerson()
{
//	Person* p = new Person{}; //pure abstract class can not be instantiated
	//delete p; 
	Person* s = new Student{};
	s->print();
	delete s;
}
void testDE()
{
	try
	{
		int res = 0;			
		res = fct2(-5); 
		std::cout << DE::n;
		res = fct2(0);
		std::cout << DE::n;		
		
		res = fct2(25);
		std::cout << DE::n;
		
	}
	catch (E&) 
	{ std::cout << DE::n;
	}		
}

void testdeck()
{
	std::deque<std::string> d; 
	d.push_back("A");
	d.push_front("B");
	d.push_back("C"); 
	d.push_front("D");
	auto itBegin = d.begin(); 
	auto itEnd = d.end();	
	itBegin++; 
	itEnd--;
	while (itBegin != itEnd)
	{
		std::cout << *itBegin << " ";
	    itBegin++;
	}
}

void except(int x)
{
	if (x < 0)
		throw Ex1{};
	else if (x == 0)
		throw Ex2{};
	cout << "Done";
}

void testEx()
{
	try
	{
		cout << "Start";
		try
		{
			except(0);
		}
		catch (Ex1& e) {}
		except(-2);
	}
	catch (Ex1& e) {}

}
void testfunction()
{
	Adder<int> add{ 5 };
	add = add + 5 + 2;
	++add;
	add + 8;
	for (auto e : add.getEl())
		std::cout << e << endl;
	cout << add.sum() << "\n";
	--add;
	cout << add.sum() << "\n";
	--(--add);	
	cout << add.sum() << "\n";
	try
	{
		--(--(--add));
	}
	catch (runtime_error& ex)
	{
		cout << ex.what(); 
	}
	
}
int main()
{
	test1();
	testStack();
	//testToDo();	
	testDc();
	//testPerson();
	//testdeck();
	//testDE();
	//testEx();
	//testfunction();
	system("pause");
	return 0;
}