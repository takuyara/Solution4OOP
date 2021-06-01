//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#pragma once
#include "vehicle.h"
class Motor: public Vehicle{
public:
	Motor(int, std::string);
	virtual void describe();
	virtual void sell();
} ;

