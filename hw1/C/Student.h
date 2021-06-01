//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#ifndef __INCLUDED_STUDENT_H__
#define __INCLUDED_STUDENT_H__
#include <string>
class Student{
	int pretimes, abstimes;
	std::string name;
public:
	Student(std::string);
	~Student();
	std::string getName();
	int getPresentTimes();
	int getAbsentTimes();
	void signIn();
	void addClass();
} ;
#endif

