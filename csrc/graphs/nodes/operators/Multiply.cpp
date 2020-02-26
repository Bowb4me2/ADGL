#include "Multiply.h"

Multiply::Multiply()
{
	this->constants.push_back(new Tensor(1.0f));
}

void Multiply::init(std::vector<Node*> predecessors)
{
}

void Multiply::operation(std::vector<Tensor*> args, Tensor* result)
{
	for (unsigned int i = 0; i < args.size(); i++)
	{
		if (i != 0)
		{
			Tensor::multiply(result, result, args[i]);
		}
		else
		{
			Tensor::multiply(result, this->constants[0], args[i]);
		}
	}
}

void Multiply::derivative(std::vector<Tensor*> args, std::vector<Tensor*>& results)
{
	for (unsigned int i = 0; i < results.size(); i++)
	{
		for (unsigned int j = 0; i < args.size(); i++)
		{
			if (i != j)
			{
				if (j != 0)
				{
					Tensor::multiply(results[i], results[i], args[j]);
				}
				else
				{
					Tensor::multiply(results[i], this->constants[0], args[j]);
				}
			}
		}
	}
}