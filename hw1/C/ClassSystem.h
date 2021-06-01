//Pionniers du TJ, benissiez-moi par votre Esprit Saints!
#ifndef __INCLUDED_CLASSSYSTEM_H__
#define __INCLUDED_CLASSSYSTEM_H__
#include "Student.h"
#include <string>
#include <vector> 
class ClassSystem{
	std::vector<Student> stuList;
public:
	ClassSystem();
	~ClassSystem();
	void addStudent(const Student &);
	void signIn(std::string);
	void addClassNumber();
	Student getStudentById(int);
	Student getStudentByName(std::string);
} ;
#endif

