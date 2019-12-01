#include "Variable.h"

Variable::Variable(Tensor& contents) : Node()
{
	
	this->grad = new Tensor(0.0f);

	this->contents = &contents;

}

void Variable::addSuccessor(Node& successor)
{
	link(this, &successor);
}

void Variable::init()
{
}

void Variable::clear()
{

}

void Variable::add_grad(Tensor* arg0)
{
	this->grad->add(arg0);
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

	

	bool all_complete = true;

	for (unsigned int i = 0; i < this->number_of_successors; i++)
	{
		all_complete = all_complete && this->successors[i]->operation_completed;
	}

	if (all_complete) 
	{

	}

}
