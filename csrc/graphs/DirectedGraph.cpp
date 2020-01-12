#include "DirectedGraph.h"

DirectedGraph::DirectedGraph()
{
}

DirectedGraph::DirectedGraph(GraphBuilder settings)
{
	settings.init();

	this->sinks = settings.sinks;

	this->sources = settings.sources;

	this->variables = settings.variables;
}

void DirectedGraph::forward()
{
	
	for (unsigned int i = 0; i < this->sinks.size(); i++)
	{
		this->sinks[i]->full_reset();
	}
	
	for (unsigned int i = 0; i < this->sources.size(); i++) 
	{
		this->sources[i]->forward();
	}

}

void DirectedGraph::backward()
{
	
	for (unsigned int i = 0; i < this->sinks.size(); i++)
	{
		dynamic_cast<Placeholder*>(this->sinks[i])->reset_sink();
	}

	for (unsigned int i = 0; i < this->sinks.size(); i++)
	{
		this->sinks[i]->backward();
	}

}
