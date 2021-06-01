//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include <iostream>
#include <string>
#include "MyAnswer.h"
using namespace std;

#define Option_A auto testA = f1(move(b)); testA.setname("testA");
#define Option_B auto testB = f2(b);
#define Option_C auto testC = f3(move(b)); testC.setname("testC");
#define Option_D auto testD = f3(move(b)); testD.setname("testD");
#define Option_E auto& testE = f4(f);
#define Option_F auto testF = f5(move(b)); testF.setname("testF");

class A {
	std::string name;
public:
	A(const std::string &_name): name(_name){
		cout << "A constructing..." << name << endl;
	}
	A(const A &a): name(a.name){
		cout << "A copy constructing..." << name << endl;
	}
	void setname(std::string _name){
		name = _name;
	}
	A(A&& a): name(a.name){
		cout << "A move constructing..." << name << endl; 
	}
	~A(){
		cout << "A destructing..." << name << endl;
	}
};

class B {
private:
	std::string name;
	static A data1;
	A data2;
public:
	B(const std::string _name): name(_name), data2(_name + ".data2"){
		cout << "B constructing..." << name << endl;
	}
	~B(){
		cout << "B destructing..." << name << endl;
	}
};

A B::data1("B::data1");

A f1(A b) {
	cout << "------after call------" << endl;
	A f = move(b);
	cout << "------before return------" << endl;
	return f;
}

A* f2(A& b) {
	cout << "------after call------" << endl;
	A* f = &b;
	cout << "------before return------" << endl;
	return f;
}


A f3(A b) {
	cout << "------after call------" << endl;
	static A f("f3::f");
	cout << "------before return------" << endl;
	return f;
}

A& f4(A* b) {
	cout << "------after call------" << endl;
	A *f = b;
	cout << "------before return------" << endl;
	return *f;
}

A f5(A&& b) {
	cout << "------after call------" << endl;
	A f = b;
	cout << "------before return------" << endl;
	return f;
}

void work()
{
	cout << "=======entering work=======" << endl;
	A b("b");
	B t("t");
	
	A f[2]{A("f[0]"), A("f[1]")};
	
	cout << "------before call------" << endl;
	Answer1 // (1)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer2 //(2)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer3 //(3)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer4 //(4)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer5 //(5)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer6 //(6)
	cout << "------after return------" << endl << endl;
	
	cout << "=======exiting work=======" << endl;
}

int main() {
	cout << "=======entering main=======" << endl;
	work();
	cout << "=======exiting main=======" << endl;
	return 0;
}
