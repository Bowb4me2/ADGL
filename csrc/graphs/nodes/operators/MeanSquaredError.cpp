#include "MeanSquaredError.h"
#include <iostream>

MeanSquaredError::MeanSquaredError()
{
}

void MeanSquaredError::init(std::vector<Node*> predecessors)
{
	this->constants.push_back(new Tensor(predecessors[1]->get_shape()));
	
	this->constants.push_back(new Tensor(2.0f));
}

void MeanSquaredError::operation(std::vector<Tensor*> args, Tensor* result)
{
	Tensor::subtract(this->constants[0], args[0], args[1]);

	Tensor::multiply(this->constants[0], this->constants[0], this->constants[0]);

	Tensor::sum(result, this->constants[0]);	
}

void MeanSquaredError::derivative(std::vector<Tensor*> args, std::vector<Tensor*>& results)
{
	Tensor::subtract(this->constants[0], args[0], args[1]);

	Tensor::multiply(results[0], this->constants[0], this->constants[1]);

	Tensor::subtract(this->constants[0], args[1], args[0]);

	Tensor::multiply(results[1], this->constants[0], this->constants[1]);
}