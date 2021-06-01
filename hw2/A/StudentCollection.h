//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#ifndef __INCLUDED_STUDENTCOLLECTION_H__
#define __INCLUDED_STUDENTCOLLECTION_H__
#include <vector>
#include "Student.h"
class StudentCollection{
	std::vector<Student> dt;
public:
	StudentCollection();
	~StudentCollection();
	void sortByScore();
	Student &operator[](std::string);
	friend std::istream &operator>>(std::istream &, StudentCollection &);
	friend std::ostream &operator<<(std::ostream &, const StudentCollection &);
} ;
#endif

