#include "Shape.h"

Shape::Shape() : shape()
{

	this->size = 1;

	this->dims = 1;

}

Shape::Shape(unsigned int size)
{

	this->size = size;

	this->dims = 1;

	this->shape.push_back(size);

}

Shape::Shape(std::vector<unsigned int> shape)
{
	
	this->size = 1;

	this->dims = (unsigned int) shape.size();

	for (unsigned int i = 0; i < shape.size(); i++) 
	{
		this->size *= shape[i];
	}

	this->shape = shape;

}

void Shape::reshape(std::vector<unsigned int> shape)
{

}

unsigned int Shape::get_size()
{
	return this->size;
}

unsigned int Shape::get_dims() 
{
	return this->dims;
}

std::vector<unsigned int> Shape::get_shape() 
{
	return this->shape;
}
