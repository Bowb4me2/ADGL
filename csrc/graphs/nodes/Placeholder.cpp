#include "Placeholder.h"
#include "Variable.h"
#include "iostream"

Placeholder::Placeholder(Tensor& contents) : Node()
{
	// make sure this has same size on update
	this->grad = new Tensor(0.0f);

	this->contents = &contents;

	this->shape = &contents.get_shape();

	this->operation = nullptr;
}

Placeholder::Placeholder(Tensor& contents, Operator& opr) : Node()
{
	// same as above comment

	this->grad = new Tensor(0.0f);

	this->contents = &contents;

	this->shape = &contents.get_shape();

	this->operation = &opr;
}

void Placeholder::addPredecessor(Node& predecessor)
{
	link(&predecessor, this);
}

void Placeholder::addSuccessor(Node& successor)
{
	link(this, &successor);
}

void Placeholder::reset_sink()
{
	for (unsigned int i = 0; i < this->number_of_predecessors; i++)
	{
		this->predecessors[i]->visited = false;

		this->predecessors[i]->predecessor->reset();
	}
}

void Placeholder::reset()
{
	this->grad->clear();

	for (unsigned int i = 0; i < this->number_of_predecessors; i++)
	{
		this->predecessors[i]->visited = false;

		this->predecessors[i]->predecessor->reset();
	}
}

void Placeholder::init()
{
	this->operation->init();

	for (unsigned int i = 0; i < this->number_of_predecessors; i++)
	{
		this->operation_grads.push_back(new Tensor(0.0f));
	}
}

void Placeholder::clear()
{
	this->contents->clear();
}

void Placeholder::forward()
{
	bool all_complete = true;

	for (unsigned int i = 0; i < this->number_of_predecessors; i++)
	{
		all_complete = all_complete && this->predecessors[i]->visited;
	}

	if (all_complete)
	{
		this->operation->operation(this->get_predecessor_tensors(), this->contents);

		for (unsigned int i = 0; i < this->number_of_successors; i++)
		{
			this->successors[i]->visited = true;

			this->successors[i]->successor->forward();
		}
	}
}

void Placeholder::backward()
{
	bool all_complete = true;

	for (unsigned int i = 0; i < this->number_of_successors; i++)
	{
		all_complete = all_complete && this->successors[i]->visited;
	}

	if (all_complete)
	{
		this->operation->derivative(this->get_predecessor_tensors(), this->operation_grads);

		for (unsigned int i = 0; i < this->number_of_predecessors; i++)
		{
			this->predecessors[i]->visited = true;

			if (dynamic_cast<Placeholder*>(this->predecessors[i]->predecessor) != nullptr)
			{
				Tensor::multiply(this->operation_grads[i], this->operation_grads[i], this->grad);

				dynamic_cast<Placeholder*>(this->predecessors[i]->predecessor)->add_grad(this->operation_grads[i]);
			}
			else if (dynamic_cast<Variable*>(this->predecessors[i]->predecessor) != nullptr)
			{
				//std::cout << "placeholder operation grads " << this->operation_grads[i]->get_contents() << std::endl;
				Tensor::multiply(this->operation_grads[i], this->operation_grads[i], this->grad);

				dynamic_cast<Variable*>(this->predecessors[i]->predecessor)->add_grad(this->operation_grads[i]);
			}

			this->predecessors[i]->predecessor->backward();
		}
	}
}

void Placeholder::set_grad(float* grad)
{
	this->grad->set_contents(grad);
}

Tensor* Placeholder::get_grad()
{
	return this->grad;
}

void Placeholder::add_grad(Tensor* grad)
{
	Tensor::add(this->grad, this->grad, grad);
}