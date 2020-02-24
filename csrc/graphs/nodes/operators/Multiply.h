#ifndef __MULTIPLY_H__
#define __MULTIPLY_H__
#include "Operator.h"

class Multiply : public Operator
{
public:

	Multiply();

	void operation(std::vector<Tensor*> args, Tensor* result) override;

	void derivative(std::vector<Tensor*> args, std::vector<Tensor*>& results) override;
};

#endif
