#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

LinkedList::LinkedList() : length{ 0 }, head{ nullptr }, tail{ nullptr } {}

LinkedList::~LinkedList()
{
	clear();
} 

Node* LinkedList::find_index(int index) const
{
	for (Node* current = head; current; current = current->next)
		if (current->index == index)
			return current;
	return nullptr;
}

void LinkedList::insert_front(int value, int index)
{
	if (find_index(index) != nullptr)
		return;

	Node* new_node = new Node(value, index);

	if (length == 0)
		head = tail = new_node;
	else
	{
		new_node->next = head;
		head->prev = new_node;

		head = new_node; // update head
	}

	++length;
} 

void LinkedList::insert_back(int value, int index)
{
	if (find_index(index) != nullptr)
		return;

	Node* new_node = new Node(value, index);

	if (length == 0)
		head = tail = new_node;
	else
	{
		new_node->prev = tail;
		tail->next = new_node;

		tail = new_node; // update tail
	}

	++length;
}

void LinkedList::set_value(int value, int index)
{
	Node* wanted_node = find_index(index);

	if (wanted_node == nullptr) // not found
		insert_back(value, index);
	else
		wanted_node->value = value;
} 

int LinkedList::get_value(int index) const
{
	Node* wanted_node = find_index(index);

	if (wanted_node == nullptr)
		throw std::runtime_error("Can't get value of not found index!");

	return wanted_node->value;
} 

void LinkedList::print_values() const
{
	for (Node* current = head; current; current = current->next)
		cout << current->value << " ";

	cout << endl;
} 

void LinkedList::add_value(int value, int index)
{
	Node* wanted_node = find_index(index);

	if (wanted_node == nullptr)
		insert_back(value, index);
	else
		wanted_node->value += value;
}

void LinkedList::add_values(LinkedList& other)
{
	for (Node* other_current = other.head; other_current; other_current = other_current->next)
		add_value(other_current->value, other_current->index);
}

bool LinkedList::is_empty() const
{
	return (length == 0);
} 

int LinkedList::get_length() const
{
	return length;
} 

void LinkedList::clear()
{
	Node* current = head;

	while (current)
	{
		Node* next = current->next;
		 
		delete current;

		current = next;
	}

	head = tail = nullptr;
	length = 0; // it should be
}

Node* LinkedList::get_head() const
{
	return head;
}
