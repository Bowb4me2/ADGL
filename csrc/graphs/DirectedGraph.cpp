#include "DirectedGraph.h"

DirectedGraph::DirectedGraph()
{
}

DirectedGraph::DirectedGraph(GraphBuilder settings)
{
	this->sinks = settings.sinks;

	this->sources = settings.sources;

	this->variables = settings.variables;
}

void DirectedGraph::forward()
{
	for (int i = 0; i < this->sources.size(); i++) 
	{
		this->sources[i]->forward();
	}
}
