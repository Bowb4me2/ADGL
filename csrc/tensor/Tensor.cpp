#include "Tensor.h"

Tensor::Tensor(float contents)
{
	this->contents = contents;

	this->size = 1;
}

void Tensor::clear()
{
	this->contents = 0;
}

void Tensor::add(Tensor* arg0)
{
	this->contents += arg0->contents;
}

void Tensor::multiply(Tensor* arg0)
{
	this->contents *= arg0->contents;
}

float Tensor::get_contents()
{
	return this->contents;
}
