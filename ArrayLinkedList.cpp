#include "ArrayLinkedList.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include <iostream>
using namespace std;

ArrayLinkedList::ArrayLinkedList(int length) : all_data(length) { }

void ArrayLinkedList::set_value(int value, int index)
{
	all_data.set_value(value, index);
	used_data.set_value(value, index);
}

int ArrayLinkedList::get_value(int index) const
{
	return used_data.get_value(index);
}

void ArrayLinkedList::print_array() const
{
	all_data.print_values();
}

void ArrayLinkedList::print_array_nonzero() const
{
	used_data.print_values();
}

void ArrayLinkedList::add(ArrayLinkedList& other)
{
	used_data.add_values(other.used_data);

	for (Node* current = used_data.get_head(); current; current = current->next)
		all_data.set_value(current->value, current->index);
}