//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include "vehicle.h"
#include <iostream>
Vehicle::Vehicle(int num, std::string name)
	: engine(name), wheel(num){
	std::cout << "Finish building a vehicle with " 
		<< wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << std::endl;
}
Vehicle::Vehicle(int num, std::string name, bool ThisClass)
	: engine(name), wheel(num){
}
void Vehicle::describe(){
	std::cout << "A vehicle with "
		<< wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << std::endl;
}

