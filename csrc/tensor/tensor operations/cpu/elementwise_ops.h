#ifndef __ELEMENTWISE_OPS_H__
#define __ELEMENTWISE_OPS_H__

namespace ops
{
	template<typename T>
	void vector_add(T* result, T* arg0, T* arg1, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = arg0[i] + arg1[i];
		}
	}

	template<typename T>
	void scalar_add(T* result, T* arg0, T* scalar, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = arg0[i] + scalar[0];
		}
	}

	template<typename T>
	void vector_sub(T* result, T* arg0, T* arg1, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = arg0[i] - arg1[i];
		}
	}

	template<typename T>
	void scalar_sub(T* result, T* arg0, T* scalar, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = arg0[i] - scalar[0];
		}
	}

	template<typename T>
	void sub_scalar(T* result, T* scalar, T* arg0, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = scalar[0] - arg0[i];
		}
	}

	template<typename T>
	void vector_mul(T* result, T* arg0, T* arg1, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = arg0[i] * arg1[i];
		}
	}

	template<typename T>
	void scalar_mul(T* result, T* arg0, T* scalar, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = arg0[i] * scalar[0];
		}
	}

	template<typename T>
	void vector_div(T* result, T* arg0, T* arg1, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = arg0[i] / arg1[i];
		}
	}

	template<typename T>
	void scalar_div(T* result, T* arg0, T* scalar, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = arg0[i] / scalar[0];
		}
	}

	template<typename T>
	void div_scalar(T* result, T* scalar, T* arg0, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[i] = scalar[0] / arg0[i];
		}
	}

	template<typename T>
	void sum(T* result, T* arg0, unsigned int size) 
	{
		for (unsigned int i = 0; i < size; i++) 
		{
			result[0] += arg0[i];
		}
	}

	template<typename T>
	void mean(T* result, T* arg0, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			result[0] += arg0[i];
		}
		result[0] /= size;
	}
}

#endif 
