#include "Add.h"
#include "iostream"

Add::Add()
{
	this->constants.push_back(new Tensor(1.0f));
}

void Add::init(std::vector<Node*> predecessors)
{
}

void Add::operation(std::vector<Tensor*> args, Tensor* result)
{
	for (unsigned int i = 0; i < args.size(); i++)
	{
		Tensor::add(result, result, args[i]);
	}
}

void Add::derivative(std::vector<Tensor*> args, std::vector<Tensor*>& results)
{
	for (unsigned int i = 0; i < results.size(); i++)
	{
		results[i] = this->constants[0];
	}
}