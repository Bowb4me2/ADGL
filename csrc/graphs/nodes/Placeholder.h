#ifndef __PLACEHOLDER_H__
#define __PLACEHOLDER_H__
#include "Node.h"
#include "operators/Operator.h"

class Placeholder : public Node
{
protected:

	Tensor* grad;

	std::vector<Tensor*> operation_grads;

	Operator* operation;

public:

	Placeholder(Tensor& contents);

	Placeholder(Tensor& contents, Operator& opr);

	void addPredecessor(Node& predececssor);

	void addSuccessor(Node& successor);

	void reset_sink();

	void reset() override;

	void init() override;

	void clear() override;

	void forward() override;

	void backward() override;

	void set_grad(float* grad);

	Tensor* get_grad();

	void add_grad(Tensor* grad) override;
};

#endif
