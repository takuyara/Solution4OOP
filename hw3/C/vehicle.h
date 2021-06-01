//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#pragma once
#include "wheel.h"
#include "engine.h"
#include <string>
class Vehicle{
protected:
	Engine engine;
	Wheel wheel;
	Vehicle(int, std::string, bool);
public:
	Vehicle(int, std::string);
	virtual void describe();
} ;

