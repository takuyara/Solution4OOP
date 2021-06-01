//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#pragma once
#include <string>
class Animal{
protected:
	std::string name;
public:
	Animal(std::string);
	virtual ~Animal();
	virtual void speak() = 0;
	virtual void swim() = 0;
	void action();
} ;
Animal::Animal(std::string nam): name(nam){ }
Animal::~Animal(){ }
void Animal::action(){
	speak();
	swim();
}

