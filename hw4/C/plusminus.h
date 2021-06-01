//Pionniers du TJ, benissiez-moi par votre Esprits Saints!
#pragma once
#include "operation.h"
class PlusOperationNode: public OperationNodeTwo{
public:
	PlusOperationNode(string name, Node *x1, Node *x2):
		OperationNodeTwo(name, x1, x2){ }
	void UpdateValue() override;
	~PlusOperationNode(){ }
} ;
class MinusOperationNode: public OperationNodeTwo{
public:
	MinusOperationNode(string name, Node *x1, Node *x2):
		OperationNodeTwo(name, x1, x2){ }
	void UpdateValue() override;
	~MinusOperationNode(){ }
} ;

