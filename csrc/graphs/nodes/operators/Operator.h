#ifndef __OPERATOR_H__
#define __OPERATOR_H__
#include "../Node.h"

class Operator 
{

public:
	
	std::vector<Tensor*> constants;

	virtual void operation(std::vector<Tensor*> args, Tensor* result) = 0;

	virtual void derivative(std::vector<Tensor*> args, std::vector<Tensor*>& results) = 0;

};

#endif
