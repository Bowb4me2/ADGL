#include "GraphBuilder.h"

GraphBuilder::GraphBuilder()
{

}

void GraphBuilder::add_source(Node& source)
{
	this->sources.push_back(&source);

	this->nodes.push_back(&source);
}

void GraphBuilder::add_sink(Placeholder& sink)
{
	this->sinks.push_back(&sink);
	
	this->nodes.push_back(&sink);
}

void GraphBuilder::add_placeholder(Placeholder& placeholder)
{
	this->nodes.push_back(&placeholder);
}

void GraphBuilder::link(Node& predecessor, Node& successor)
{
	Node::link(&predecessor, &successor);
}

GraphBuilder& GraphBuilder::operator=(GraphBuilder& a)
{
	return a;
}
