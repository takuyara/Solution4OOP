//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#pragma once
class Shape{
public:
	Shape();
	virtual ~Shape();
	virtual double getArea() = 0;
} ;
class Rectangle: public Shape{
	double width, height;
public:
	Rectangle(double, double);
	~Rectangle();
	double getArea();
} ;
class Circle: public Shape{
	double radius;
public:
	Circle(double);
	~Circle();
	double getArea();
} ;

