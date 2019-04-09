
#ifndef NODE_H_
#define NODE_H_

template <typename E>
class Node
{
private:
	E element;
	Node* next;
public:
	Node(E element, Node* next)
	{
		this->element=element;
		this->next=next;
	}
	E getElement();	
	Node* getNext();	
	void setNext(Node* newNext);

};

template<typename E>
E Node<E>::getElement()
{
		return element;
}

template<typename E>
Node<E>* Node<E>::getNext()
{
		return this->next;
}
template<typename E>
void Node<E>::setNext(Node<E>* newNext)
{
		this->next=newNext;
}

#endif /* NODE_H_ */
