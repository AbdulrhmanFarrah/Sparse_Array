#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList
{
private:
	
	Node* head{};
	Node* tail{};
	int length{};

	Node* find_index(int index) const; // find the node with this index and return pointer to it, if not found return nullptr

	void insert_front(int value, int index); // insert new node to the data of the list (make new head)
	void insert_back(int value, int index); // insert new node to the end of the list (make new tail)
	void add_value(int value, int index); // add value for an used index, but if not used then insert it

public:
	LinkedList();
	~LinkedList(); // delete the list 
	
	LinkedList(const LinkedList&) = delete;
	LinkedList& operator = (const LinkedList&) = delete;

	void set_value(int value, int index); // if index not found then insert it, otherwise update it
	int get_value(int index) const; // return value if found, otherwise throw an error

	void print_values() const; // print values without indexes. *** Note: the sparse all_data is not sorted ***

	void add_values(LinkedList& other); // add each (if index exist) or insert new values of other list to our list

	bool is_empty() const; // returns true if the list is empty otherwise returns false
	int get_length() const; // returns the current length of the list

	void clear(); // delete the whole linked list, and make the head and tail nullptr

	Node* get_head() const;
};

