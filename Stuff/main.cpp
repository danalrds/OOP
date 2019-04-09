#include <stdlib.h>
#include <iostream>
#include "Classes.h"
#include <Windows.h>
#include <crtdbg.h>
#include "Sales.h"
#include "Template.h"
void channeling()
{

	{
		Channel* ch = nullptr;
		delete ch;
		Channel* tel = new Telephone{ "0260" };
		Channel* ch2 = nullptr;
		Channel* ch3 = nullptr;
		ch2 = new Failover{ new Fax{ "0259" }, new SMS{ "0258" } };
		ch3 = new Failover{ new Failover{ new Telephone{ "0260" }, new Fax{ "0259" } }, new SMS{ "0258" } };
		Contact c{ tel, ch2, ch3 };
		//c.sendAlarm("Heyyyyyoooooo");
	}
}

void saling()
{
	SaleItem i1{ 123,100 };
	SaleItem i2{ 123,150 };
	SaleItem i3{ 124,150 };
	Sale s{};
	s.add(i1);
	s.add(i2);
	s.add(i3);
	Discount* d1 = new ItemDiscount{ 123,10 };
	Discount* d2 = new ItemDiscount{ 124,15 };
	SumDiscount sum{};
	sum.add(d1);
	sum.add(d2);
	std::cout << "Total discount " << sum.calc(s);
	delete d1;
	delete d2;
}
void templating()
{
	Car c{ "Audi",9 };
	Adder < Car, int > a{c,11};
	Car c2{ "MERCEDES",99 };
	Car c3{ "bmw",5 };
	a.add(c2,8);
	a.add(c3, 12);
	a.print();
	
	a.sortByFirst();
	a.print();
	a.sortBySecond();
	a.print();
}
int main()
{
	//channeling();
	//saling();
	templating();
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}