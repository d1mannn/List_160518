#include "List.h"

template<typename T>
inline List<T>::Node::Node(T date)
{
	this->date = date;
	this->nextPtr = nullptr;
}

template<typename T>
inline List<T>::List()
{
	firstPtr = nullptr;
	lastPtr = nullptr;
	count = 0;
}

template<typename T>
void List<T>::print()
{
	Node *curPtr = firstPtr;
	cout << curPtr->date << endl;

	while (curPtr != lastPtr)
	{
		curPtr = curPtr->nextPtr;
		cout << curPtr->date << endl;
	}
}



template<typename T>
void List<T>::push_back(T date)
{
	if (count == 0)
	{
		firstPtr = new Node(date);
		lastPtr = firstPtr;
	}
	else
	{
		lastPtr->nextPtr = new Node(date);
		lastPtr = lastPtr->nextPtr;		
	}
	count++;
}

template<typename T>
void List<T>::push_front(T date)
{
	if (count == 0)
	{
		firstPtr = new Node(date);
		lastPtr = firstPtr;
	}
	else
	{
		Node *e = new Node(date);
		e->nextPtr = firstPtr;
		firstPtr = e;		
	}
	count++;
}

template<typename T>
List<T>::~List()
{
	Node *curPtr;
	Node n = *firstPtr;

	curPtr = firstPtr;
	delete firstPtr;
	while (n.nextPtr != lastPtr)
	{
		curPtr = n.nextPtr;
		n = *curPtr;
		delete curPtr;
	}
}


