#include "Placeholder.h"

Placeholder::Placeholder(Tensor& contents) : Node()
{

	this->contents = &contents;

	this->operation = nullptr;

}

Placeholder::Placeholder(Tensor& contents, Operator& opr) : Node()
{

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
		this->operation->operation();
		for (unsigned int i = 0; i < this->number_of_successors; i++)
		{
			this->successors[i]->operation_completed = true;
			this->successors[i]->successor->forward();
		}
	}
}

void Placeholder::backward()
{
	
}
