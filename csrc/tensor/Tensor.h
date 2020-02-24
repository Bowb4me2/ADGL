#ifndef __TENSOR_H__
#define __TENSOR_H__
#include "Shape.h"

class Tensor 
{

protected:

	unsigned int size;

	Shape shape;

	float* contents;

public:

	Tensor(float contents);

	Tensor(unsigned int size);

	Tensor(unsigned int size, float contents);

	Tensor(Shape shape);

	static void add(Tensor* result, Tensor* arg0, Tensor* arg1);

	static void subtract(Tensor* result, Tensor* arg0, Tensor* arg1);

	static void multiply(Tensor* result, Tensor* arg0, Tensor* arg1);

	static void divide(Tensor* result, Tensor* arg0, Tensor* arg1);

	static void sum(Tensor* result, Tensor* arg0);

	

	void clear();

	// void reshape(Shape shape);

	void set_contents(Tensor* arg0);

	void set_contents(float* arg0);

	float get_contents();

	unsigned int get_size();

	Shape get_shape();

};

#endif
