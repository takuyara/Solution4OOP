//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#ifndef __INCLUDED_STUDENT_H__
#define __INCLUDED_STUDENT_H__
#include <string>
#include <iostream>
class Student{
	std::string name;
	int sC, sM, sE;
public:
	bool operator<(const Student &);
	Student(std::string nm): name(nm), sC(0), sM(0), sE(0){ }
	void SetScore(std::string, int);
	std::string GetName() const;
	int sA() const;
	friend std::ostream& operator<<(std::ostream &, const Student &);
} ;
#endif

