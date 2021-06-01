all: main
main: engine.o wheel.o vehicle.o motor.o car.o main.o
	g++ -o main car.o engine.o main.o motor.o vehicle.o wheel.o
car.o: car.cpp car.h
	g++ -o car.o -c car.cpp
motor.o: motor.cpp motor.h
	g++ -o motor.o -c motor.cpp
vehicle.o: vehicle.cpp vehicle.h
	g++ -o vehicle.o -c vehicle.cpp
engine.o: engine.cpp engine.h
	g++ -o engine.o -c engine.cpp
wheel.o: wheel.cpp wheel.h
	g++ -o wheel.o -c wheel.cpp
car.h: vehicle.h
motor.h: vehicle.h
vehicle.h: wheel.h engine.h
