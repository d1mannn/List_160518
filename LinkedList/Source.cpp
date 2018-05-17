#include "List.h"
#include "List.cpp"

int main()
{
	List<int> L;
	L.push_back(5);
	L.push_back(12);
	L.push_back(112);
	L.push_front(10);
	cout << L.size() << endl;
	L.print();
	/*L.~List();*/
	system("pause");
	return 0;
}