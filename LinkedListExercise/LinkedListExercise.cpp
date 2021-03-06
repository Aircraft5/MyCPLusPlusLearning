// LinkedListExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyDataStructures.h"

using namespace std;
using namespace mydatastructures;


int main(int argc, char** argv)
{
	LinkedList list;
	LinkedList list2;
	LinkedList* list3;	

	list.addItem(0);
	list.addItem(1);
	list.addItem(2);
	list.addItem(3);
	list.addItem(4, 0);
	list.addItem(5, 1);
	list.addItem(6, 2);
	list.addItem(4, 6);

	list.removeItem(6);
	list.removeItem(0);

	cout << "--------" << endl;
	list.print();

	list2.addItem(1);
	list2.addItem(2);
	list2.addItem(3);
	list2.addItem(4);

	cout << "--------" << endl;
	list2.print();

	list3 = list2 + list;

	cout << "--------" << endl;
	list3->print();
	list3->removeItem(0);

	cout << "--------" << endl;
	list3->print();

	cout << "--------" << endl;
	cout << list3;

	Vector v1(2);

	cout << "Vector size: " << v1.size() << endl;

	Vector v2;

	v2 = v1;

	v1[0] = 2;
	v2[1] = 3;

	cout << "v1[0] " << v1[0] << " v1[0] " << v2[0] << endl;
	
    return getchar();
}

