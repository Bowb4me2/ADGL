#ifndef __TENSOR_H__
#define __TENSOR_H__
//#include "Shape.h"

class Tensor 
{

private:

	unsigned int size;

	// Shape shape;

	float contents;

public:
	
	Tensor();

	Tensor(float contents);

	// Tensor(unsigned int size);

	// Tensor(Shape shape);

	void clear();

	void add(Tensor* arg0);

	void multiply(Tensor* arg0);

	// void reshape(Shape shape);

	float get_contents();

};

#endif
