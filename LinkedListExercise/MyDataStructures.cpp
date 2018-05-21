#include "stdafx.h"
#include "MyDataStructures.h"

struct mydatastructures::ListBlock {
	int data;
	ListBlock* next = nullptr;
};

mydatastructures::LinkedList::LinkedList(void):
	_head(nullptr),
	_tail(nullptr),
	_length(0)
{};

mydatastructures::LinkedList::~LinkedList()
{
	ListBlock* nextBlock = _head;	

	while (nextBlock != nullptr) {
		ListBlock* blockToDelete = nextBlock;
		nextBlock = blockToDelete->next;		
		delete blockToDelete;
	}
};

void mydatastructures::LinkedList::addItem(int data)
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
void mydatastructures::LinkedList::addItem(int data, int position)
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
void mydatastructures::LinkedList::removeItem(int position)
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
int mydatastructures::LinkedList::getItem(int position)
{
	ListBlock* block = _head;

	for (int i = 0; i < position; i++) {
		block = block->next;
	}

	return block->data;
}
int mydatastructures::LinkedList::getLength()
{
	return _length;
};
void mydatastructures::LinkedList::print()
{
	ListBlock* block = _head;

	while (block != nullptr) {
		std::cout << block->data << std::endl;
		block = block->next;
	}
}
mydatastructures::LinkedList* mydatastructures::LinkedList::operator+(LinkedList& secondList)
{
	LinkedList* result = new LinkedList();
	ListBlock* block = _head;

	while (block != nullptr) {
		result->addItem(block->data);
		block = block->next;
	}

	block = secondList.getHead();

	while (block != nullptr) {
		result->addItem(block->data);
		block = block->next;
	}

	return result;
}
mydatastructures::ListBlock* mydatastructures::LinkedList::getHead()
{
	return _head;
}
mydatastructures::ListBlock* mydatastructures::LinkedList::getTail()
{
	return _tail;
}

std::ostream& mydatastructures::operator<<(std::ostream& os, mydatastructures::LinkedList& list)
{
	ListBlock* block = list.getHead();

	while (block != nullptr) {
		os << block->data << ' ';
		block = block->next;
	}

	os << std::endl;

	return os;
}

mydatastructures::Vector::Vector() : elem{ new double[0] }, sz{ 0 } {}

mydatastructures::Vector::Vector(int s) : elem{ new double[s] }, sz{ s }
{
	for (int i = 0; i != s; i++)
		elem[i] = 0;
}

mydatastructures::Vector::Vector(const Vector& a) : elem{ new double[a.sz] },
	sz{ a.sz }
{
	std::cout << "Copy";
	for (int i = 0; i != sz; ++i) {
		elem[i] = a.elem[i];
	}
}

mydatastructures::Vector::Vector(Vector&& a) : elem{ a.elem }, sz{ a.sz } {
	std::cout << "move";
	a.elem = nullptr;
	a.sz = 0;
}

mydatastructures::Vector& mydatastructures::Vector::operator=(mydatastructures::Vector&& a) {
	elem = a.elem;
	sz = a.sz;

	std::cout << "move1";
	a.elem = nullptr;
	a.sz = 0;

	return *this;
}

mydatastructures::Vector& mydatastructures::Vector::operator=(const mydatastructures::Vector& a)
{
	double* p = new double[a.sz];
	for (int i = 0; i != a.sz; ++i) {
		p[i] = a.elem[i];
	}

	delete[] elem;
	elem = p;

	sz = a.sz;
	return *this;
}

mydatastructures::Vector::~Vector() { delete[] elem; }

double& mydatastructures::Vector::operator[](int i) const { return elem[i]; }

int mydatastructures::Vector::size() const { return sz; }