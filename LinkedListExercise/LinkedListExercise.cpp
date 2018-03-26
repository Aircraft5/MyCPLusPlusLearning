// LinkedListExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MyDataStuctures.h"

using namespace std;

int main(int argc, char** argv)
{
	mydatastructures::LinkedList list = mydatastructures::LinkedList();
	mydatastructures::LinkedList list2 = mydatastructures::LinkedList();
	mydatastructures::LinkedList list3 = mydatastructures::LinkedList();

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

	list3 = list2 + list;

	cout << "--------" << endl;
	list3.print();

	list3.removeItem(0);

	cout << "--------" << endl;
	list3.print();

	cout << "--------" << endl;
	list2.print();

    return getchar();
}

