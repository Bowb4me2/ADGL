#include <iostream>
#include "graphs/nodes/Constant.h"
#include "graphs/nodes/Placeholder.h"
#include "tensor/Tensor.h"
#include "graphs/DirectedGraph.h"
#include "graphs/GraphBuilder.h"



int main() 
{



	Tensor t1(1);

	Tensor t2(1);

	Tensor t3(1);

	Constant constant1(t1);

	Constant constant2(t2);

	Placeholder placeholder(t3);

	GraphBuilder settings;

	settings.add_sink(placeholder);

	settings.add_source(constant1);

	settings.add_source(constant2);

	settings.link(constant1, placeholder);

	settings.link(constant2, placeholder);

	std::cout << "hello 18 " << constant1.get_number_of_successors() << " " << placeholder.get_number_of_predecessors();
	
	DirectedGraph g(settings);

	g.forward();
	
	std::cout << std::endl << settings.sinks[0]->get_number_of_predecessors();


}
