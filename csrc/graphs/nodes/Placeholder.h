#ifndef __PLACEHOLDER_H__
#define __PLACEHOLDER_H__
#include "Node.h"
#include "operators/Operator.h"

class Placeholder : public Node 
{

protected:

	Operator* operation;

public:

	Placeholder(Tensor& contents);

	Placeholder(Tensor& contents, Operator& opr);

	void addPredecessor(Node& predececssor);

	void addSuccessor(Node& successor);

	void clear() override;

	void forward() override;

	void backward() override;
};

#endif
