//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
//It rained on us at 4am.
#include <list>
#include <vector>
template <typename T>
class MyQueriable{
	std::vector<T> a;
public:
	MyQueriable(const std::vector<T> &v){
		a.clear();
		for (auto i: v) a.push_back(i);
	}
	MyQueriable(const std::list<T> &v){
		a.clear();
		for (auto i: v) a.push_back(i);
	}
	~MyQueriable(){
		a.clear();
	}
	template <typename Op1>
	MyQueriable<T> where(Op1 func){
		std::vector<T> v1;
		v1.clear();
		for (auto i: a) if (func(i)) v1.push_back(i);
		auto x = MyQueriable<T>(v1);
		v1.clear();
		return x;
	}
	template <typename Op1>
	MyQueriable<T> apply(Op1 func){
		std::vector<T> v1;
		v1.clear();
		for (auto i: a) v1.push_back(func(i));
		auto x = MyQueriable<T>(v1);
		v1.clear();
		return x;
	}
	T sum(){
		T s = 0;
		for (auto i: a) s = s + i;
		return s;
	}
	int size(){
		return a.size();
	}
	T &operator[](int i){
		return a[i];
	}
} ;
template <typename T>
auto from(const std::vector<T> &v){
	return MyQueriable<T>(v);
}
template <typename T>
auto from(const std::list<T> &v){
	return MyQueriable<T>(v);
}

