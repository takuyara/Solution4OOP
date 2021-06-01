//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#pragma once
#include "vehicle.h"
class Car: public Vehicle{
public:
	Car(int, std::string);
	virtual void describe();
} ;

