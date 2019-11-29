#include "Variable.h"

Variable::Variable(Tensor& contents) : Node()
{
	this->contents = &contents;
}

void Variable::addSuccessor(Node& successor)
{
	link(this, &successor);
}

void Variable::clear()
{
}

void Variable::forward()
{
	for (unsigned int i = 0; i < this->number_of_successors; i++)
	{
		this->successors[i]->operation_completed = true;
		this->successors[i]->successor->forward();
	}
}

void Variable::backward()
{
}
