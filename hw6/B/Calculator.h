#pragma once
#include "LoadStrategy.h"
#include "PayStrategy.h"

class Calculator {								
	LoadStrategy *_loads;
	PayStrategy *_pays;
public:
	Calculator(LoadStrategy *, PayStrategy *);
	float load();
	float pay(float);
};

Calculator::Calculator(LoadStrategy *_l, PayStrategy *_p):
	_loads(_l), _pays(_p){
}

float Calculator::load(){
	return _loads->work();
}

float Calculator::pay(float money){
	return _pays->work(money);
}

