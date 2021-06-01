//Pionniers du TJ, benissiez-moi par votre Esprit Saints!
#include <string>
#include <iostream>
#include "Student.h"
bool Student::operator<(const Student &y){
	if (sA() != y.sA()) return sA() < y.sA();
	if (sC != y.sC) return sC < y.sC;
	if (sM != y.sM) return sM < y.sM;
	return sE < y.sE;
}
void Student::SetScore(std::string subj, int sc){
	if (subj == "Chinese") sC = sc;
	if (subj == "Math") sM = sc;
	if (subj == "English") sE = sc;
}
std::string Student::GetName() const{
	return name;
}
int Student::sA() const{
	return sC + sM + sE;
}
std::ostream &operator<<(std::ostream &os, const Student &st){
	os << st.name << "-Total-" << st.sA() << "-Chinese-" << st.sC
		<< "-Math-" << st.sM << "-English-" << st.sE;
	return os;
}

