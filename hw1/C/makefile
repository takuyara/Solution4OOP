all: main
main: main.o Student.o ClassSystem.o
	g++ -o main main.o Student.o ClassSystem.o
main.o: main.cpp
	g++ main.cpp -c
Student.o: Student.cpp
	g++ Student.cpp -c
ClassSystem.o: ClassSystem.cpp
	g++ ClassSystem.cpp -c
