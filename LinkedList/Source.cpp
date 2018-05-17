#include "List.h"
#include "List.cpp"

int main()
{
	setlocale(LC_ALL, "Rus");
	List<int> L;
	L.push_back(5);
	L.push_back(12);
	L.push_back(112);
	L.push_front(10);
	cout << L.find(12) << endl;
	cout << endl;
	cout <<"2й" <<L[2] << endl;
	cout << endl << "До Удаления" << endl;
	L.print();
	L.delete_elm(10);
	cout << endl << "После Удаления" << endl;
	//cout << L.size() << endl;
	L.print();
	L.remove_back();
	cout << endl;
	L.print();
	L.remove_first();
	cout << endl;
	L.print();
	/*L.~List();*/
	//system("pause");
	return 0;
}