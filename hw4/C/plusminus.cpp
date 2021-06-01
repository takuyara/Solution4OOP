//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#include "plusminus.h"
void PlusOperationNode::UpdateValue(){
	value_ = input1->value() + input2->value();
}
void MinusOperationNode::UpdateValue(){
	value_ = input1->value() - input2->value();
}

