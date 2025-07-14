#include "ArrayList.h"
#include <iostream>
using namespace std;

ArrayList::ArrayList(int length) : length(length)
{
	data = new int[length] (); // this syntax intialize all of them to zero
}

ArrayList::~ArrayList()
{
	if (data)
		delete[] data;
}

void ArrayList::set_value(int value, int index)
{
	if (index <= -1 || length <= index)
		throw std::runtime_error("index out of bounds!! , set_value function inside ArrayList.cpp");

	data[index] = value;
}

int ArrayList::get_value(int index) const
{
	if (index <= -1 || length <= index)
		throw std::runtime_error("index out of bounds!! , get_value function inside ArrayList.cpp");

	return data[index];
}

int* ArrayList::front() const
{
	return data;
} 

int ArrayList::get_length() const
{
	return length;
}

void ArrayList::print_values() const
{
	for (int index = 0; index < length; ++index)
		cout << data[index] << " ";
	cout << endl;
}