#pragma once
#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"
#include "Node.h"
using namespace std;

class ArrayLinkedList
{
private:
	LinkedList used_data; // used values, without zeros. *** Note: if you set a zero then it will be insert inside it ***
	ArrayList all_data; // all values including zeros

public:
	ArrayLinkedList(int length); // initialize the all_data with zeros

	// may be just for now 
	ArrayLinkedList(const ArrayLinkedList&) = delete; 
	ArrayLinkedList& operator = (const ArrayLinkedList&) = delete;

	void set_value(int value, int index);
	int get_value(int index) const;

	void print_array() const; // print the whole all_data
	void print_array_nonzero() const; // print just the used values of all_data (linked list)

	void add(ArrayLinkedList& other); // add other values to our values
};

