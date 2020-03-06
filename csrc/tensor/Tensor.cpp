#include "Tensor.h"
#include "tensor operations/cpu/elementwise_ops.h"
#include "tensor operations/cpu/matrix_mul_ops.h"
#include <iostream>

Tensor::Tensor(float contents) : 
	shape(1), 
	size(1), 
	contents(new float(contents))
{
//alloc mem here
}

Tensor::Tensor(unsigned int size) : 
	shape(size), 
	size(size), 
	contents(new float[size])
{
//alloc mem here
}

Tensor::Tensor(unsigned int size, float contents) : 
	Tensor(size)
{
	for (unsigned int i = 0; i < this->size; i++)
	{
		this->contents[i] = contents;
	}
}

Tensor::Tensor(Shape shape) : 
	shape(shape), 
	size(shape.get_size()), 
	contents(new float[shape.get_size()])
{
//alloc mem here
}

Tensor::Tensor(const std::initializer_list<float>& contents) : 
	Tensor(static_cast<unsigned int>(contents.size()))
{
	int i = 0;
	for (auto &element : contents) 
	{
		this->contents[i++] = element;
	}
}

void Tensor::add(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	if (arg0->size == 1)
	{
		ops::scalar_add<float>(result->contents, arg1->contents, arg0->contents, result->size);
	}
	else if (arg1->size == 1)
	{
		ops::scalar_add<float>(result->contents, arg0->contents, arg1->contents, result->size);
	}
	else
	{
		ops::vector_add<float>(result->contents, arg0->contents, arg1->contents, result->size);
	}
}

void Tensor::subtract(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	if (arg0->size == 1)
	{
		ops::scalar_sub<float>(result->contents, arg1->contents, arg0->contents, result->size);
	}
	else if (arg1->size == 1)
	{
		ops::scalar_sub<float>(result->contents, arg0->contents, arg1->contents, result->size);
	}
	else
	{
		ops::vector_sub<float>(result->contents, arg0->contents, arg1->contents, result->size);
	}
}

void Tensor::multiply(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	if (arg0->size == 1)
	{
		ops::scalar_mul<float>(result->contents, arg1->contents, arg0->contents, result->size);
	}
	else if (arg1->size == 1)
	{
		ops::scalar_mul<float>(result->contents, arg0->contents, arg1->contents, result->size);
	}
	else
	{
		ops::vector_mul<float>(result->contents, arg0->contents, arg1->contents, result->size);
	}
}

void Tensor::divide(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	if (arg0->size == 1)
	{
		ops::scalar_div<float>(result->contents, arg1->contents, arg0->contents, result->size);
	}
	else if (arg1->size == 1)
	{
		ops::scalar_div<float>(result->contents, arg0->contents, arg1->contents, result->size);
	}
	else
	{
		ops::vector_div<float>(result->contents, arg0->contents, arg1->contents, result->size);
	}
}

void Tensor::sum(Tensor* result, Tensor* arg0)
{
	ops::sum<float>(result->contents, arg0->contents, result->size);
}

void Tensor::mean(Tensor* result, Tensor* arg0) 
{
	ops::mean<float>(result->contents, arg0->contents, result->size);
}

void Tensor::transpose(Tensor* result, Tensor* arg0)
{
	ops::transpose<float>(result->contents, arg0->contents, arg0->shape.get_shape()[0], arg0->shape.get_shape()[1]);
}

void Tensor::dot(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	ops::dot_product<float>(result->contents, arg0->contents, arg1->contents, arg0->size, arg1->size);
}

void Tensor::outer(Tensor* result, Tensor* arg0, Tensor* arg1)
{
	ops::outer_product<float>(result->contents, arg0->contents, arg1->contents, arg0->size, arg1->size);
}

void Tensor::fill(float arg0)
{
	for (unsigned int i = 0; i < this->size; i++)
	{
		this->contents[i] = arg0;
	}
}

void Tensor::clear()
{
	for (unsigned int i = 0; i < this->size; i++)
	{
		this->contents[i] = 0.0f;
	}
}

void Tensor::set_contents(Tensor* arg0)
{
	this->contents = arg0->contents;
}

void Tensor::set_contents(float* arg0)
{
	this->contents = arg0;
}

float* Tensor::get_contents()
{
	return this->contents;
}

unsigned int Tensor::get_size()
{
	return this->size;
}

Shape Tensor::get_shape()
{
	return this->shape;
}

std::ostream& operator<<(std::ostream& out, Tensor& arg0)
{
	out << "Tensor(";

	for (unsigned int i = 0; i < arg0.size - 1; i++)
	{
		out << arg0.get_contents()[i] << ", ";
	}
	out << arg0.get_contents()[arg0.size - 1] << ")";
	return out;
}

std::ostream& operator<<(std::ostream& out, Tensor* arg0)
{
	out << "Tensor(";

	for (unsigned int i = 0; i < arg0->size - 1; i++)
	{
		out << arg0->get_contents()[i] << ", ";
	}

	out << arg0->get_contents()[arg0->size - 1] << ")";

	return out;
}


Tensor::~Tensor()
{
	delete this->contents;
}
