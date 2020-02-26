#ifndef __MEANSQUAREDERROR_H__
#define __MEANSQUAREDERROR_H__
#include "Operator.h"

class MeanSquaredError : public Operator
{
public:

	MeanSquaredError();

	void init(std::vector<Node*> predecessors) override;

	void operation(std::vector<Tensor*> args, Tensor* result) override;

	void derivative(std::vector<Tensor*> args, std::vector<Tensor*>& results) override;
};

#endif
