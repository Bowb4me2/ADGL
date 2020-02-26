#include "GraphBuilder.h"
#include <iostream>

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

	(&sink)->set_grad(new float(1.0f));
}

void GraphBuilder::add_placeholder(Placeholder& placeholder)
{
	this->nodes.push_back(&placeholder);
}

void GraphBuilder::link(Node& predecessor, Node& successor)
{
	Node::link(&predecessor, &successor);
}

void GraphBuilder::init()
{
	for (unsigned int i = 0; i < this->nodes.size(); i++)
	{
		this->nodes[i]->init();
	}
}

GraphBuilder& GraphBuilder::operator=(GraphBuilder& a)
{
	return a;
}