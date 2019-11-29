#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include "Node.h"

class Variable : public Node 
{

public:

	Variable(Tensor& contents);

	void addSuccessor(Node& predececssor);

	void clear() override;

	void forward() override;

	void backward() override;

};

#endif
