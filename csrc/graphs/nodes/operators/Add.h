#ifndef __ADD_H__
#define __ADD_H__
#include "Operator.h"

class Add : public Operator
{
public:

	Add();

	void operation(std::vector<Tensor*> args, Tensor* result) override;

	void derivative(std::vector<Tensor*> args, std::vector<Tensor*>& results) override;
};

#endif
