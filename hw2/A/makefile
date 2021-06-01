all: main
main: main.o Student.o StudentCollection.o
	g++ -o main main.o Student.o StudentCollection.o -std=c++11
main.o: main.cpp Student.h StudentCollection.h
	g++ -o main.o -c main.cpp -std=c++11
Student.o: Student.cpp Student.h
	g++ -o Student.o -c Student.cpp -std=c++11
StudentCollection.o: StudentCollection.cpp Student.h StudentCollection.h
	g++ -o StudentCollection.o -c StudentCollection.cpp -std=c++11