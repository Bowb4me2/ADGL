#include <iostream>
#include "graphs/nodes/Constant.h"
#include "graphs/nodes/Placeholder.h"
#include "tensor/Tensor.h"
#include "graphs/DirectedGraph.h"
#include "graphs/GraphBuilder.h"
#include"graphs/nodes/operators/Add.h"



int main() 
{

	Add add;

	Tensor t1(30.f);

	Tensor t2(33.0f);

	Tensor t3(0.0f);

	Constant constant1(t1);

	Constant constant2(t2);

	Placeholder placeholder(t3, add);

	GraphBuilder settings;

	settings.add_sink(placeholder);

	settings.add_source(constant1);

	settings.add_source(constant2);

	settings.link(constant1, placeholder);

	settings.link(constant2, placeholder);

	std::cout << "hello 20 " << constant1.get_number_of_successors() << " " << placeholder.get_number_of_predecessors();
	
	DirectedGraph g(settings);

	g.forward();
	
	std::cout << std::endl << settings.sinks[0]->get_number_of_predecessors();

	std::cout << std::endl << settings.sinks[0]->get_contents()->get_contents();

}
