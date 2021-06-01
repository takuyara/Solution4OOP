#ifndef CONTAINER_H
#define CONTAINER_H
#include <set>
#include <vector>
#include <algorithm>
#include "BasicContainer.h"
template<class A, class C>
class Container : public BasicContainer<A>
{
    C base;
public:
    void insert(const A &x)
    {
        for(auto t = base.begin(); t != base.end(); ++t)
            if(*t > x)
            {
                base.insert(t, x);
                return;
            }
        base.insert(base.end(), x);
    }
    A find(int k)
    {
        auto t = base.begin();
        while(--k)
            ++t;
        return *t;
    }
};
template<class A>
class Container<A , std::vector<A>>: public BasicContainer<A>{
    std::vector<A> base;
    bool sorted;
public:
	Container(): base(), sorted(false){
	}
    void insert(const A &x){
        base.push_back(x);
    }
    A find(int k){
        if (!sorted){
        	std::sort(base.begin(), base.end());
        	sorted = true;
        }
        return base[k - 1];
    }
};
template <typename A>
class Container<A, std::multiset<A>>: public BasicContainer<A>{
	std::multiset<A> base;
public:
	void insert(const A &x){
		base.insert(x);
	}
	A find(int k){
		auto p = base.begin();
		while (--k) ++p;
		return *p;
	}
} ;
#endif
