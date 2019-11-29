#ifndef __OPERATOR_H__
#define __OPERATOR_H_
#include "../Node.h"

class Operator 
{

public:

	void operator()();

	virtual void operation() = 0;

	virtual void derivative() = 0;

	Node* parent;

};

#endif
