//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#pragma once
#include "what.h"
#include <string>
class Alien: virtual public WhatCanMotion, virtual public WhatCanSpeak{
	std::string name;
public:
	Alien(std::string nam): name(nam){ }
	void speak(){
		std::cout << name << " is speaking\n";
	}
	void motion(){
		std::cout << name << " is moving\n";
	}
	void stop(){
		std::cout << name << " stops\n";
	}
	~Alien(){ }
} ;

