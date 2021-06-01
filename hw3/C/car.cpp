//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include "car.h"
Car::Car(int num, std::string name):
	Vehicle(num, name, false){
	std::cout << "Finish building a car with "
		<< wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << std::endl;
}
void Car::describe(){
	std::cout << "A car with "
		<< wheel.get_num() << " wheels and a " << engine.get_name() << " engine." << std::endl;
}

