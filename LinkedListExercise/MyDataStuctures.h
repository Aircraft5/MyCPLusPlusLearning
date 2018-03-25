#pragma once

#ifndef _MY_DATA_STRUCTURES_
#define _MY_DATA_STRUCTURES_

namespace mydatastructures {
	struct ListBlock;

	class LinkedList {
	public:
		void addItem(int data);
		void addItem(int data, int position);
		void removeItem(int position);
		int getItem(int position);
		int getLength();
		void print();
	private:
		ListBlock * _head = nullptr;
		ListBlock* _tail = nullptr;
		int _length = 0;
};
}

#endif // _MY_DATA_STRUCTURES_