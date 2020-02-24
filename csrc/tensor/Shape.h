#ifndef __SHAPE_H__
#define __SHAPE_H__
#include <vector>


class Shape 
{

private:

	unsigned int size;

	unsigned int dims;

	std::vector<unsigned int> shape;
	
public:

	Shape();

	Shape(unsigned int size);

	Shape(std::vector<unsigned int> shape);

	void reshape(std::vector<unsigned int> shape);

	unsigned int get_size();

	unsigned int get_dims();

	std::vector<unsigned int> get_shape();

};

#endif
