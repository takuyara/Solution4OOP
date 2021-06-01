//Pionniers du TJ, benissiez-moi par votre Esprit Saints!
#include "Array.h"
#include <algorithm>
Array::Array(int l = 0): len(l){
	head = len ? new Node[len] : nullptr;
}
Array::~Array(){
	delete[] head;
}
Node &Array::operator[](int pos){
	return head[pos];
}
void Array::update(int x, int y){
	head[x] = head[y];
}
void Array::swap(int x, int y){
	Node t(std::move(head[x]));
	head[x] = std::move(head[y]);
	head[y] = std::move(t);
}
void Array::insert(int pos, int val){
	for (int i = len - 1; i > pos; --i)
		head[i] = std::move(head[i - 1]);
	head[pos] = std::move(Node(val));
}

