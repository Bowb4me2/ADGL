#include <iostream>

#include "graphs/nodes/Constant.h"
#include "graphs/nodes/Placeholder.h"
#include "tensor/Tensor.h"
#include "graphs/DirectedGraph.h"
#include "graphs/GraphBuilder.h"
#include "graphs/nodes/operators/Add.h"
#include "graphs/nodes/operators/Multiply.h"


int main()
{
	
	Tensor t1(21.1f);

	Tensor t2(33.0f);

	Tensor t3(0.0f);

	Tensor t4(0.0f);

	std::cout << t1.get_shape().get_size() + 1 << std::endl;

	Variable constant1(t1);

	Variable constant2(t2);

	Add oper;

	Multiply mul;

	Placeholder placeholder(t3, oper);

	Placeholder sink(t4, oper);

	GraphBuilder settings;

	settings.add_placeholder(placeholder);

	settings.add_source(constant1);

	settings.add_source(constant2);

	settings.add_sink(sink);

	settings.link(constant1, placeholder);

	settings.link(constant2, placeholder);

	settings.link(constant1, sink);

	settings.link(placeholder, sink);

	std::cout << "hello 26 " << constant1.get_number_of_successors() << " " << placeholder.get_number_of_predecessors();

	DirectedGraph g(settings);

	for (unsigned int i = 0; i < 20; i++)
	{

		g.forward();

		g.backward();

		std::cout << "Output: " << settings.sinks[0]->get_contents()->get_contents() << std::endl;
	
	}

	std::cout << "const1 Val: " << constant1.get_contents()->get_contents() << std::endl;

}




