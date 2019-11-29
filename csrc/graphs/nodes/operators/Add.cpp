#include "Add.h"

void Add::operation(std::vector<Tensor*> args, Tensor* result)
{
	for (int i = 0; i < args.size(); i++) 
	{
		result->add(args[i]);
	}
}

void Add::derivative(std::vector<Tensor*> args, std::vector<Tensor*> results)
{

}
