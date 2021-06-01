#pragma once
#include <list>
#include <iostream>
#include <memory>
#include <string>

#include "CustomClass.h"

using std::string;
class Object;

class Content
{
public:
	virtual void output(std::ostream& out) const{ //virtual function for output
		std::cout << "the operator is not supported for this type." << std::endl;
	}
	virtual Content &operator+=(int x){
		return *this;
	}
	virtual Content &operator+=(const string &x){
		return *this;
	}
};

class IntContent: public Content
{
private:
	int x;
public:
	IntContent(int _x): x(_x) {
	}
	void output(std::ostream& out) const{
		out << x;
	}
	Content &operator+=(int x1){
		x += x1;
		return *this;
	}
};

class StringContent: public Content
{
private:
	std::string x;
public:
	StringContent(std::string _x): x(_x) {}
	void output(std::ostream& out) const{
		out << x;
	}
	Content &operator+=(const string &x1){
		x += x1;
		return *this;
	}
};

class VectorContent: public Content
{
private:
	std::vector<Object> x;
public:
	VectorContent(const std::vector<Object>& _x): x(_x) {}
	Object &getIndex(int i){
		return x[i];
	}
};
class CustomContent: public Content
{
private:
	CustomClass x;
public:
	CustomContent(const CustomClass& _x): x(_x) {}
};

class Object
{
private:
	std::shared_ptr<Content> pt;

public:
	Object() {}
	Object(int x): pt(new IntContent(x)){
		
	}
	Object(const std::string &x): pt(new StringContent(x)){
		
	}
	
	Object(const std::vector<Object> &x): pt(new VectorContent(x)){
	
	}
	Object(const CustomClass &x): pt(new CustomContent(x)){
	
	}

	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt->output(out);
		return out;
	}

	Object& operator+=(int y){
		pt->operator+=(y);
		return *this;
	}
	Object& operator+=(const std::string &y){
		pt->operator+=(y);
		return *this;
	}
	
	Object &operator=(const Object &y){
		pt = y.pt;
		return *this;
	}
	
	Object &operator=(int x) {
		pt = std::make_shared<IntContent>(x);
		return *this;
	}
	Object &operator=(const std::string &x){
		pt = std::make_shared<StringContent>(x);
		return *this;
	}
	
	Object &operator=(const std::vector<Object> &x){
		pt = std::make_shared<VectorContent>(x);
		return *this;
	}
	Object &operator=(const CustomClass &x){
		pt = std::make_shared<CustomContent>(x);
		return *this;
	}
	Object &operator[](int x){
		auto p1 = std::dynamic_pointer_cast<VectorContent>(pt);
		return p1->getIndex(x);
	}
	//need more operators......
};
