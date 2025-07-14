#pragma once
#include <iostream>
using namespace std;

class ArrayList
{
private:
	int* data{};
	const int length{};

public:
	ArrayList(int length);
	~ArrayList();

	ArrayList(const ArrayList&) = delete;
	ArrayList& operator=(const ArrayList&) = delete;

	void set_value(int value, int index);
	int get_value(int index) const;

	int* front() const; // return pointer that points to the front of the all_data
	int get_length() const;

	void print_values() const;

};

