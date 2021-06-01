//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include "ClassSystem.h"
#include <vector>
#include <iostream>
ClassSystem::ClassSystem(){
	stuList.clear();
}
ClassSystem::~ClassSystem(){
	stuList.clear();
}
void ClassSystem::addStudent(const Student &stu){
	stuList.push_back(stu);
}
void ClassSystem::signIn(std::string stuName){
	for (auto &cur: stuList)
		if (cur.getName() == stuName){
			//std::cerr << cur.getPresentTimes() << cur.getAbsentTimes() << std::endl;
			cur.signIn();
			break;
		}
}
void ClassSystem::addClassNumber(){
	for (auto &cur: stuList){
		cur.addClass();
		//std::cerr << "addClassNumber" << cur.getPresentTimes() << cur.getAbsentTimes() << std::endl;
	}
}
Student ClassSystem::getStudentById(int id){
	return stuList[id];
}
Student ClassSystem::getStudentByName(std::string stuName){
	for (auto &cur: stuList)
		if (cur.getName() == stuName) return cur;
}

