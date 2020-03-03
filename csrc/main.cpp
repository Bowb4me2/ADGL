#include <iostream>

#include "graphs/nodes/Constant.h"
#include "graphs/nodes/Placeholder.h"
#include "tensor/Tensor.h"
#include "graphs/DirectedGraph.h"
#include "graphs/GraphBuilder.h"
#include "graphs/nodes/operators/Add.h"
#include "graphs/nodes/operators/Multiply.h"
#include "graphs/nodes/operators/MeanSquaredError.h"

int main()
{

	MeanSquaredError add;

	//Add add;

	//Multiply add;
	
	GraphBuilder settings;

	Tensor t1(2, 1.1f);

	Tensor t2(2, 2.0f);

	Tensor t3(2, 0.0f);



	Variable var(t1);

	Constant constant(t2);

	Placeholder sink(t3, add);

	settings.add_sink(sink);

	settings.add_source(var);

	settings.add_source(constant);

	settings.link(constant, sink);

	settings.link(var, sink);

	DirectedGraph g(settings);

	for (unsigned int i = 0; i < 40; i++)
	{
		g.forward();

		g.backward();

		std::cout << "Output1: " << settings.sinks[0]->get_contents()->get_contents() << std::endl;
	}
	
	std::cout << "variable: " << settings.nodes[01]->get_contents()->get_contents() << "\n";
	
	std::cout << "Joe: " << settings.nodes[1]->get_contents();
}
