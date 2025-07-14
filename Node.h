#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	Node* next{};
	Node* prev{};
	int index{};
	int value{};

	Node(int value, int index);
};

