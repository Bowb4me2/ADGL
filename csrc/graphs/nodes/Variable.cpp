#include "Variable.h"
#include "iostream"

Variable::Variable(Tensor& contents) : Node()
{
	this->grad = new Tensor(0.0f);

	this->learning_rate = new Tensor(0.001f);

	this->contents = &contents;
}

void Variable::addSuccessor(Node& successor)
{
	link(this, &successor);
}

void Variable::reset()
{
	this->grad->clear();

	for (unsigned int i = 0; i < this->number_of_predecessors; i++)
	{
		this->predecessors[i]->visited = false;

		this->predecessors[i]->predecessor->reset();
	}
}

void Variable::init()
{
}

void Variable::clear()
{
	this->grad->clear();
}

void Variable::add_grad(Tensor* arg0)
{
	Tensor::add(this->grad, this->grad, arg0);
}

void Variable::forward()
{
	for (unsigned int i = 0; i < this->number_of_successors; i++)
	{
		this->successors[i]->visited = true;

		this->successors[i]->successor->forward();
	}
}

void Variable::backward()
{
	bool all_complete = true;

	for (unsigned int i = 0; i < this->number_of_successors; i++)
	{
		all_complete = all_complete && this->successors[i]->visited;
	}

	if (all_complete)
	{
		std::cout << "Variable grad: " << this->grad->get_contents() << std::endl;
		//Tensor::multiply(this->grad, this->grad, this->learning_rate);
		Tensor::subtract(this->contents, this->contents, this->grad);
	}
}