//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#pragma once
#include "Node.h"
class Array{
	Node *head;
	int len;
public:
	Array(int);
	~Array();
	Node &operator[](int);
	void update(int, int);
	void swap(int, int);
	void insert(int, int);
} ;

