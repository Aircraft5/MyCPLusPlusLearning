#include "stdafx.h"
#include <iostream>
#include "MyDataStuctures.h"

using namespace std;
using namespace mydatastructures;

struct mydatastructures::ListBlock {
	int data;
	ListBlock* next = nullptr;
};

void LinkedList::addItem(int data)
{
	ListBlock* listBlock = new ListBlock();

	listBlock->data = data;

	if (_length == 0) {
		_head = listBlock;
		_tail = _head;
	}
	else {
		_tail->next = listBlock;
		_tail = listBlock;
	}

	_length++;
};
void LinkedList::addItem(int data, int position)
{
	ListBlock* listBlock = new ListBlock();
	ListBlock* listBlockToEdit = _head;

	listBlock->data = data;

	if (position == 0) {
		listBlock->next = _head;
		_head = listBlock;
	}
	else {
		for (int i = 0; i < position - 1; i++) {
			listBlockToEdit = listBlockToEdit->next;
		}

		listBlock->next = listBlockToEdit->next;
		listBlockToEdit->next = listBlock;
	}

	_length++;
};
void LinkedList::removeItem(int position)
{
	ListBlock* blockToEdit = _head;
	ListBlock* blockToDelete = _head;

	if (position == 0) {
		_head = _head->next;
		delete blockToDelete;
	}
	else {
		for (int i = 0; i < position - 1; i++) {
			blockToEdit = blockToEdit->next;
		}

		blockToDelete = blockToEdit->next;
		blockToEdit->next = blockToDelete->next;
		delete blockToDelete;
	}

	_length--;
};
int LinkedList::getItem(int position)
{
	ListBlock* block = _head;

	for (int i = 0; i < position; i++) {
		block = block->next;
	}

	return block->data;
}
int LinkedList::getLength()
{
	return _length;
};
void LinkedList::print()
{
	ListBlock* block = _head;

	while (block != nullptr) {
		cout << block->data << endl;
		block = block->next;
	}
}
