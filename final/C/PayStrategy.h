#pragma once
#include <string>

class PayStrategy {							
public:	
	virtual double pay(std::string name, double money) = 0;
};


class NormalStrategy : public PayStrategy {
public:	
	double pay(std::string name, double money){
		return money;
	}
};

class SwiftStrategy : public PayStrategy {	
public:
	double pay(std::string name, double money){
		if (money <= 10000.0) return money - 10;
		double tmp = money / 1000.0;
		if (tmp > 20) tmp = 20;
		return money - tmp;
	}
};

class BitcoinStrategy : public PayStrategy {	
	double pay(std::string name, double money){
		return money - 0.01 * (name.length() + 8);
	}
};
