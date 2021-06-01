//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
//It rained on us at 4am.
#pragma once
#include <string>
#include <iostream>

class LoadStrategy {						
public:
	virtual float work() = 0;		
};


class NumberLoadStrategy : public LoadStrategy {	
public:
	float work();
};

class WordLoadStrategy : public LoadStrategy {	
public:
	float work();
};

float NumberLoadStrategy::work(){
	float x;
	std::cin >> x;
	return x;
}

float WordLoadStrategy::work(){
	std::string str1("");
	float x = 0;
	while ((std::cin >> str1), str1 != "#"){
		int cur;
		if (str1 == "one") cur = 1;
		if (str1 == "two") cur = 2;
		if (str1 == "three") cur = 3;
		if (str1 == "four") cur = 4;
		if (str1 == "five") cur = 5;
		if (str1 == "six") cur = 6;
		if (str1 == "seven") cur = 7;
		if (str1 == "eight") cur = 8;
		if (str1 == "nine") cur = 9;
		if (str1 == "zero") cur = 0;
		x = x * 10 + cur;
	}
	return x;
}

