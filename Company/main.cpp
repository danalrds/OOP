#include "Company.h"
#include "Employee.h"
#include "Manager.h"
#include <iostream>
using namespace std;
void test()
{
	Employee* emp1 = new Employee{"John",1500};
	Employee* emp2 = new Manager{ "Marco",5320,900 };
	Employee* emp3 = new Employee{ "Christian",1600 };
	Employee* emp4 = new Manager{ "Ryan",3000,500 };
	std::vector<Employee*> employees;
	employees.push_back(emp1);
	employees.push_back(emp2);
	employees.push_back(emp3);
	employees.push_back(emp4);
	for (auto e : employees)
	{
		cout << e->toString();
		cout << e->computeSalary();
		cout << endl;
	}
	for (auto e : employees)
		delete(e);
}

int main()
{
	system("color f4");
	test();
	
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}