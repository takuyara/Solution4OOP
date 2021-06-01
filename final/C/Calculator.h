#pragma once
#include <string>
#include "OccupationStrategy.h"
#include "PayStrategy.h"

class Calculator {								
	OccupationStrategy *os;
	PayStrategy *ps;
public:
	Calculator(OccupationStrategy *os1, PayStrategy *ps1): os(os1), ps(ps1){ }
	double getSalary(double base, double bonus, double level){
		return os->getSalary(base, bonus, level);
	}
	double pay(std::string name, double money){
		return ps->pay(name, money);
	}
};

