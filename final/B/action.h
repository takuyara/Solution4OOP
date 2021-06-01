//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#pragma once
#include <vector>
#include "animal.h"
void action(Animal *p, std::vector<Dog> &dogs, std::vector<Bird> &birds){
	Dog *p1 = dynamic_cast<Dog*>(p);
	if (p1){
		dogs.push_back(std::move(*p1));
	} else {
		Bird *p2 = dynamic_cast<Bird*>(p);
		birds.push_back(std::move(*p2));
	}
}

