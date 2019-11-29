#include "Constant.h"

Constant::Constant(Tensor& contents) : Node()
{
	this->contents = &contents;
}

void Constant::addSuccessor(Node& successor)
{
	link(this, &successor);
}

void Constant::clear()
{
}

void Constant::forward()
{
	for (unsigned int i = 0; i < this->number_of_successors; i++)
	{
		this->successors[i]->operation_completed = true;
		this->successors[i]->successor->forward();
	}
}

void Constant::backward()
{
}
