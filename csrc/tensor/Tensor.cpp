#include "Tensor.h"

Tensor::Tensor(float contents)
{

	this->contents = new float(contents);

	this->size = 1;

}

void Tensor::add(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	for (unsigned int i = 0; i < result->size; i++) 
	{
		result->contents[i] = arg0->contents[i] + arg1->contents[i];
	}
}

void Tensor::subtract(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	for (unsigned int i = 0; i < result->size; i++)
	{
		result->contents[i] = arg0->contents[i] - arg1->contents[i];
	}
}

void Tensor::multiply(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	for (unsigned int i = 0; i < result->size; i++)
	{
		result->contents[i] = arg0->contents[i] * arg1->contents[i];
	}
}

void Tensor::divide(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	for (unsigned int i = 0; i < result->size; i++)
	{
		result->contents[i] = arg0->contents[i] / arg1->contents[i];
	}
}

void Tensor::clear()
{
	this->contents = new float(0.0f);
}

void Tensor::set_contents(Tensor* arg0)
{
	this->contents = arg0->contents;
}

void Tensor::set_contents(float* arg0)
{
	this->contents = arg0;
}

float Tensor::get_contents()
{
	return *this->contents;
}
