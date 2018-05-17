#pragma once
#include "Library.h"
template <typename T>
class List
{
private:
	class Node
	{	
	public:
		T date;
		Node* nextPtr;
		Node(T date);		

	}*firstPtr, *lastPtr;
	size_t count;
public:
	List();
	void push_back(T date);
	void push_front(T date);
	void print();
	size_t size() { return count; }
	virtual ~List();
};


