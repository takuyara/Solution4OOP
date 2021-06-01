//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include "Student.h"
#include <string>
#include <iostream>
Student::Student(std::string stuName){
	name = stuName;
	pretimes = abstimes = 0;
}
Student::~Student(){
}
std::string Student::getName(){
	return name;
}
int Student::getPresentTimes(){
	return pretimes;
}
int Student::getAbsentTimes(){
	return abstimes;
}
void Student::signIn(){
	++pretimes;
	--abstimes;
	//std::cerr << pretimes << " " << abstimes << std::endl;
}
void Student::addClass(){
	++abstimes;
	//std::cerr << "addClass";
}

