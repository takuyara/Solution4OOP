//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
//It rained on us at 4am.
#pragma once

class PayStrategy {		
public:
	virtual float work(float) = 0;						
};


class NormalStrategy : public PayStrategy {	
public:
	float work(float);
};

class RebateStrategy : public PayStrategy {	
public:
	float work(float);
};

class ReturnStrategy : public PayStrategy {	
public:
	float work(float);
};

float NormalStrategy::work(float x){
	return x;
}

float RebateStrategy::work(float x){
	return x * 0.38;
}

float ReturnStrategy::work(float x){
	if (x - 25.0 >= -1e-9) x -= 10;
	return x;
}

