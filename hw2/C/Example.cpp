#include <iostream>
#include "Example.h"

using namespace std;

int total = 0;

Example::Example(int data) {
	id = ++total;
	cdata = data;
	std::cout << "Example #" << id << " is created" << std::endl;
}

void Example::getData() {
	std::cout << "The data of Example #" << id << " is " << cdata << std::endl;
}

Example::~Example() {
	std::cout << "Example #" << id << " is destroyed" << std::endl;
}
