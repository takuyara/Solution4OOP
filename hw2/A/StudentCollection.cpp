//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include <iostream>
#include <algorithm>
#include "StudentCollection.h"
StudentCollection::StudentCollection(){
	dt.clear();
}
StudentCollection::~StudentCollection(){
	dt.clear();
}
void StudentCollection::sortByScore(){
	std::sort(dt.rbegin(), dt.rend());
}
Student &StudentCollection::operator[](std::string name){
	for (auto &x: dt)
		if (x.GetName() == name) return x;
	dt.push_back(Student(name));
	return *dt.rbegin();
}
std::istream &operator>>(std::istream &is, StudentCollection &sc){
	std::string str1;
	is >> str1;
	int p1 = str1.find("-"), p2 = str1.rfind("-");
	sc[str1.substr(0, p1)].
		SetScore(str1.substr(p1 + 1, p2 - p1 - 1), std::stoi(str1.substr(p2 + 1, str1.npos)));
	return is;
}
std::ostream &operator<<(std::ostream &os, const StudentCollection &sc){
	for (auto &x: sc.dt) os << x << std::endl;
	return os;
}

