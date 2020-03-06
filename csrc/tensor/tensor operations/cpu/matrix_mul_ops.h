#ifndef __MATRIX_MUL_OPS_H__
#define __MATRIX_MUL_OPS_H__

namespace ops
{
	template<typename T>
	void transpose(T* result, T* arg0, unsigned int size_x, unsigned int size_y) 
	{
		for (unsigned int j = 0; j < size_y; j++) 
		{
			for (unsigned int i = 0; i < size_x; i++) 
			{
				result[i * size_y + j] = arg0[j * size_x + i];
			}
		}
	}

	template<typename T>
	void outer_product(T* result, T* arg0, T* arg1, unsigned int size_x, unsigned int size_y) 
	{
		for (unsigned int j = 0; j < size_y; j++) 
		{
			for (unsigned int i = 0; i < size_x; i++) 
			{
				result[j * size_x + i] = arg0[i] * arg1[j];
			}
		}
	}

	template<typename T>
	void dot_product(T* result, T* arg0, T* arg1, unsigned int size_x, unsigned int size_y) 
	{
		for (unsigned int j = 0; j < size_y; j++) 
		{
			for (unsigned int i = 0; i < size_x; i++) 
			{
				result[j] += arg0[i] * arg1[j * size_x + i];
			}
		}
	}
}

#endif 
