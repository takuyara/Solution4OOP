all: main
main: main.o product.o sum.o
	g++ -o main main.o product.o sum.o
main.o: main.cpp functions.h
	g++ -c main.cpp $(FLAG)
product.o: product.cpp functions.h
	g++ -c product.cpp $(FLAG)
sum.o: sum.cpp functions.h
	g++ -c sum.cpp $(FLAG)
clean:
	rm *.o main
