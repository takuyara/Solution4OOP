//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include "motor.h"
#include <iostream>
Motor::Motor(int num, std::string name):
	Vehicle(num, name, false){
	std::cout << "Finish building a motor with "
		<< wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << std::endl;
}
void Motor::describe(){
	std::cout << "A motor with "
		<< wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << std::endl;
}
void Motor::sell(){
	std::cout << "A motor is sold!" << std::endl;
}

