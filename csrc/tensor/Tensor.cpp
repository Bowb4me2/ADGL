#include "Tensor.h"

Tensor::Tensor(float contents) : shape(1)
{
	this->contents = new float(contents);

	this->size = 1;
}

Tensor::Tensor(unsigned int size) : shape(size)
{
	this->contents = new float[size];

	this->size = size;
}

Tensor::Tensor(unsigned int size, float contents) : shape(size)
{
	this->contents = new float[size];

	this->size = size;

	for (unsigned int i = 0; i < this->size; i++)
	{
		this->contents[i] = contents;
	}
}

Tensor::Tensor(Shape shape)
{
	this->contents = new float[shape.get_size()];

	this->size = shape.get_size();

	this->shape = shape;
}

void Tensor::add(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	if (arg0->size == 1)
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[0] + arg1->contents[i];
		}
	}
	else if (arg1->size == 1)
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[i] + arg1->contents[0];
		}
	}
	else
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[i] + arg1->contents[i];
		}
	}
}

void Tensor::subtract(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	if (arg0->size == 1)
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[0] - arg1->contents[i];
		}
	}
	else if (arg1->size == 1)
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[i] - arg1->contents[0];
		}
	}
	else
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[i] - arg1->contents[i];
		}
	}
}

void Tensor::multiply(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	if (arg0->size == 1)
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[0] * arg1->contents[i];
		}
	}
	else if (arg1->size == 1)
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[i] * arg1->contents[0];
		}
	}
	else
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[i] * arg1->contents[i];
		}
	}
}

void Tensor::divide(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	if (arg0->size == 1)
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[0] / arg1->contents[i];
		}
	}
	else if (arg1->size == 1)
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[i] / arg1->contents[0];
		}
	}
	else
	{
		for (unsigned int i = 0; i < arg0->size; i++)
		{
			result->contents[i] = arg0->contents[i] / arg1->contents[i];
		}
	}
}

void Tensor::sum(Tensor* result, Tensor* arg0)
{
	for (unsigned int i = 0; i < arg0->size; i++)
	{
		result->contents[0] += arg0->contents[i];
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

unsigned int Tensor::get_size()
{
	return this->size;
}

Shape Tensor::get_shape()
{
	return this->shape;
}