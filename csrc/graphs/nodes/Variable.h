#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include "Node.h"

class Variable : public Node 
{

protected:

	Tensor* grad;

public:

	Variable(Tensor& contents);

	void addSuccessor(Node& predececssor);

	void init() override;

	void clear() override;

	void add_grad(Tensor* arg0);

	void forward() override;

	void backward() override;

};

#endif
