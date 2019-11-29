#ifndef __GRAPHBUILDER_H__
#define __GRAPHBUILDER_H__
#include "nodes/Node.h"
#include "nodes/Variable.h"
#include "nodes/Placeholder.h"
#include <vector>

class GraphBuilder
{

public:

	std::vector<Node*> sources;

	std::vector<Node*> sinks;

	std::vector<Variable*> variables;

	std::vector<Node*> nodes;

	GraphBuilder();

	void add_source(Node& source);

	void add_sink(Placeholder& sink);

	void add_placeholder(Placeholder& placeholder);

	void link(Node& predecessor, Node& successor);

	GraphBuilder& operator=(GraphBuilder& a);

};

#endif
