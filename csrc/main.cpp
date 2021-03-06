#include <iostream>

#include "graphs/nodes/Constant.h"
#include "graphs/nodes/Placeholder.h"
#include "tensor/Tensor.h"
#include "graphs/DirectedGraph.h"
#include "graphs/GraphBuilder.h"
#include "graphs/nodes/operators/Add.h"
#include "graphs/nodes/operators/Multiply.h"
#include "graphs/nodes/operators/MeanSquaredError.h"

Tensor t1({1.1f, 2.1f});

Tensor t2(2, 4.0f);

Tensor t3(1, 0.0f);

Tensor test1(4, 2.0f);

Tensor test2(16, 1.0f);

Tensor test3(4, 2.0f);

int main()
{

	Tensor::outer(&test2, &test1, &test3);

	std::cout << "outer: " << test2 << "\n";

	MeanSquaredError mse;
	
	GraphBuilder settings;

	Variable var(t1);

	Constant constant(t2);

	Placeholder sink(t3, mse);

	settings.add_sink(sink);

	settings.add_source(var);

	settings.add_source(constant);

	settings.link(constant, sink);

	settings.link(var, sink);

	DirectedGraph g(settings);

	for (unsigned int i = 0; i < 100; i++)
	{
		g.forward();
		
		g.backward();

		std::cout << "Output: " << settings.sinks[0]->get_contents() << std::endl;
		std::cout << "Variable: " << settings.nodes[1]->get_contents() << std::endl;
		std::cout << "Constant: " << settings.nodes[2]->get_contents() << std::endl << std::endl;
	}
}