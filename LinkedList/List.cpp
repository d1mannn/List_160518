#include "List.h"

template<typename T>
List<T>::Node::Node(T date)
{
	this->date = date;
	this->nextPtr = nullptr;
}

template<typename T>
List<T>::List()
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
void List<T>::remove_back()
{	
	if (size() == 1)
	{
		delete firstPtr;
		firstPtr = nullptr;
		lastPtr = nullptr;
		count--;
	}
	else
	{
		Node * curptr;
		curptr = firstPtr;
		while (curptr->nextPtr != lastPtr)
		{
			curptr = curptr->nextPtr;
		}
		delete lastPtr;
		lastPtr = curptr;
		curptr->nextPtr = nullptr;
		count--;
	}
	
}

template<typename T>
void List<T>::remove_first()
{
	if (size() == 1)
	{
		delete firstPtr;
		firstPtr = nullptr;
		lastPtr = nullptr;
		count--;
	}
	else
	{
		Node * curptr;
		curptr = firstPtr->nextPtr;
		delete firstPtr;
		firstPtr = curptr;
		count--;
	}
}

template<typename T>
bool List<T>::find(T date)
{	
	Node * curptr = firstPtr;
	int cc = 0;
	while (curptr != nullptr)
	{
		if (curptr->date == date)
			return cc;
		curptr = curptr->nextPtr;
		cc++;
	}
	return false;
}

template<typename T>
void List<T>::delete_elm(T date)
{
	Node * curptr = firstPtr;
	Node * curptr2;
	while (curptr != nullptr)
	{
		if (curptr->date == date)
		{
			if (curptr == firstPtr)
				firstPtr = curptr->nextPtr;
			curptr2 = curptr->nextPtr;
			delete curptr;
			curptr = curptr2;
			/*curptr = curptr2->nextPtr;

			curPtr = firstPtr->nextPtr;
			delete firstPtr;
			firstPtr = curPtr;*/
			count--;
		}
		else
			curptr = curptr->nextPtr;
		
	}
}

template<typename T>
T & List<T>::operator[](int index)
{	
	Node * curptr;
	curptr = firstPtr;
	int cc = 0;
	while (curptr != nullptr)
	{
		if (index == cc)
			return curptr->date;
		cc++;
		curptr = curptr->nextPtr;
	}
	// TODO: insert return statement here
}

template<typename T>
List<T>::~List()
{
	// ÄÅÑÒÐÓÊÒÎÐ ÎÁßÇÀÒÅËÅÍ!!!!!!!!!!
	Node * curPtr;
	while (firstPtr != nullptr)
	{
		curPtr = firstPtr->nextPtr;
		delete firstPtr;
		firstPtr = curPtr;
		
	}
	delete firstPtr;
}


