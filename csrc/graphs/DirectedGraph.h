#ifndef __DIRECTEDGRAPH_H__
#define __DIRECTEDGRAPH_H__
#include "nodes/Node.h"
#include "nodes/Variable.h"
#include "GraphBuilder.h"
#include <vector>

class DirectedGraph
{

private:

	std::vector<Node*> sources;

	std::vector<Node*> sinks;

	std::vector<Variable*> variables;

public:

	DirectedGraph();

	DirectedGraph(GraphBuilder settings);

	void forward();

	void backward();

};

#endif
