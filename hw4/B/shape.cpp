//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include "Shape.h"
const double PI = 3.14;
Shape::Shape(){
}
Shape::~Shape(){
}
Rectangle::Rectangle(double w, double h): width(w), height(h){
}
Rectangle::~Rectangle(){
}
double Rectangle::getArea(){
	return width * height;
}
Circle::Circle(double r): radius(r){
}
Circle::~Circle(){
}
double Circle::getArea(){
	return PI * radius * radius;
}

