#ifndef __CONSTANT_H__
#define __CONSTANT_H__
#include "Node.h"

class Constant : public Node
{
public:

	Constant(Tensor& contents);

	void addSuccessor(Node& predececssor);

	void reset() override;

	void init() override;

	void clear() override;

	void forward() override;

	void backward() override;
};

#endif