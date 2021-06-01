#ifndef BASICCONTAINER_H
#define BASICCONTAINER_H

template<class A>
class BasicContainer
{
public:
    virtual ~BasicContainer(){}
    virtual void insert(const A &x) = 0;
    virtual A find(int k) = 0;
};
#endif
