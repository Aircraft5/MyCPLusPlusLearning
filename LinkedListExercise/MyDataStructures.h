#pragma once

#ifndef _MY_DATA_STRUCTURES_
#define _MY_DATA_STRUCTURES_

namespace mydatastructures {
	struct ListBlock;

	class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		void addItem(int data);
		void addItem(int data, int position);
		void removeItem(int position);
		int getItem(int position);
		int getLength();
		void print();
		LinkedList operator+(LinkedList& secondList);
		ListBlock* getHead();
		ListBlock* getTail();
		friend std::ostream& operator<<(std::ostream& os, LinkedList& list);
	private:
		ListBlock* _head;
		ListBlock* _tail;
		int _length;
	};
}

#endif // _MY_DATA_STRUCTURES_