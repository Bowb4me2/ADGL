#include "Placeholder.h"
#include "Variable.h"

Placeholder::Placeholder(Tensor& contents) : Node()
{

	// make sure this has same size on update
	this->grad = new Tensor(0.0f);

	this->grad;

	this->contents = &contents;

	this->operation = nullptr;

}

Placeholder::Placeholder(Tensor& contents, Operator& opr) : Node()
{

	// same as above comment
	this->grad = new Tensor(0.0f);

	this->contents = &contents;

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

void Placeholder::init()
{
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
		all_complete = all_complete && this->predecessors[i]->operation_completed;
	}
	
	if (all_complete) 
	{

		this->operation->operation(this->get_predecessor_tensors(), this->contents);
		
		for (unsigned int i = 0; i < this->number_of_successors; i++)
		{
		
			this->successors[i]->operation_completed = true;
			
			this->successors[i]->successor->forward();
		
		}

	}

}

void Placeholder::backward()
{
	
	bool all_complete = true;

	for (unsigned int i = 0; i < this->number_of_successors; i++) 
	{
		all_complete = all_complete && this->successors[i]->operation_completed;
	}

	if (all_complete) 
	{
		for (unsigned int i = 0; i < this->number_of_predecessors; i++) 
		{
			
			this->predecessors[i]->operation_completed = true;

			this->operation->derivative(this->get_predecessor_tensors(), this->operation_grads);

			if (dynamic_cast<Placeholder*>(this->predecessors[i]->predecessor) != nullptr) 
			{
				
				this->operation_grads[i]->multiply(this->grad);
				
				dynamic_cast<Placeholder*>(this->predecessors[i]->predecessor)->add_grad(this->operation_grads[i]);
			
			}
			else if (dynamic_cast<Variable*>(this->predecessors[i]->predecessor) != nullptr)
			{
				dynamic_cast<Variable*>(this->predecessors[i]->predecessor)->add_grad(this->operation_grads[i]);
			}

			this->predecessors[i]->predecessor->backward();

		}
	}

}

Tensor* Placeholder::get_grad()
{
	return this->grad;
}

void Placeholder::add_grad(Tensor* grad)
{
	this->grad->add(grad);
}
