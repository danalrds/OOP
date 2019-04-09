//============================================================================
// Name        : Sem3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Node.h"
#include "SList.h"
//#include "Student.h"
using namespace std;

int main() {	
	SList<int> a;
	a.addLast(1);
	a.addLast(2);
	a.addLast(3);
	SList<int>::iterator it=a.begin();
	cout<< it.getElem();	
	while (it.hasNext())
	{
		it++;
		cout<< it.getElem();		
	}
	int i;
	cin>>i;
	return 0;
}
