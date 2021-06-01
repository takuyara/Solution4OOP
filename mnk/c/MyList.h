#pragma once
#include <list>
#include <memory>
#include <iostream>

class MyList
{
private:
	std::shared_ptr< std::list<int> > pt; // a pointer to the real container
	std::list<int>::iterator left, right; // the position of slice is [left, right). 'left' is included, 'right' is excluded.
	bool empty;
	std::list<int>::iterator forward(int pos) const{
		// count from 'left', find the element at position 'pos'.
		auto now = left;
		while(pos--) now++;
		return now;
	}

public:
	MyList(): pt(new std::list<int>()), empty(true){
		left = pt->begin();
		right = pt->end();
		// Actually, left = right = pt->end(), because there is no element in the list.
	}
	MyList(std::shared_ptr< std::list<int> > pt1, 
		std::list<int>::iterator lft, std::list<int>::iterator rig)
	: pt(pt1), left(lft), right(rig), empty(lft == rig){
	}

	void append(int i){
		//std::cout << "append " << i << std::endl;
		right = pt->insert(right, i);
		if (empty){
			left = right;
			empty = false;
		}
		++right;
		//insert i just before 'right'. 'right' and 'left' will be still valid (because we use list, not vector).
		// DEBUG !! Why I can't insert i??
	}

	int &operator[](int pos) const{
		return *forward(pos); // access the element at the 'pos'
	}

	void output(std::ostream &out) const{
		/*
		for (auto i : *pt){
			out << i << " ";
			out << std::endl;
		}
		*/
		out << "[";
		if (left != right){
			auto now = left;
			out << *now;
			now ++;
			for(; now != right; now++){
				out << "," << *now;
			}
		}
		out << "]";
	}
	MyList operator()(int x, int y){
		return MyList(pt, forward(x), forward(y));
	}
};

std::ostream &operator<<(std::ostream &os, const MyList &lst){
	lst.output(os);
	return os;
}

