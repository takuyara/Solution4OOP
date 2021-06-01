#pragma once

class OccupationStrategy {	
public:							
	virtual double getSalary(double base, double bonus, double level) = 0;
};

class SalesmanStrategy : public OccupationStrategy {
public:
	double getSalary(double base, double bonus, double level){
		double tms = 0;
		if (level >= 60 && level < 70) tms = 0.6;
		if (level >= 70 && level < 80) tms = 0.7;
		if (level >= 80) tms = 1;
		return base + tms * bonus;
	}
};

class DeveloperStrategy : public OccupationStrategy {	
public:
	double getSalary(double base, double bonus, double level){
		return base + bonus / 100 * level;
	}
};
