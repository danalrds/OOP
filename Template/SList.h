#ifndef SLIST_H_
#define SLIST_H_
#include "Node.h"
template<typename E> class SList;
template<typename E> class Iterator;

template<typename E>
class Iterator
{
	friend class SList<E>;
private:
	Node<E>* current;	
	Iterator(Node<E>* newCurrent)
	{
		current=newCurrent;
	}
public:		
	//Iterator(){}
	Iterator& operator ++()
	{
		if (current!=0){
			current=current->getNext();
		}
		return *this;
	}
	int hasNext()
	{
		if (current!=0){
			if (current->getNext()!=0) return 1;
			else return 0;
		}
		return 0;
		
	}
	E getElem()
	{
		return this->current->getElement();
	}

};

template<typename E>
class SList
{
private:
	Node<E>* head;
public:
	typedef Iterator<E> iterator;
	SList(){ head=0;}
	void addLast(E elem){
		if (head==0)
		{
			Node<E>* node=new Node<E>(elem, 0);
			head=node;
		}
		else
		{
			Node<E>* p=head;
			while (p->getNext()!=0)
				p=p->getNext();
			p->setNext(new Node<E>(elem,0));
		}
	}
	Iterator<E> begin()
	{
		return *(new Iterator<E>(head));
	}

};

#endif /* SLIST_H_ */
