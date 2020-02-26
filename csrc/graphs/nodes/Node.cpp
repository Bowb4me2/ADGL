#include "Node.h"
#include <typeinfo>
#include <iostream>


// public Node::Edge(Node*, Node*)
// constructor for edges with predecessor and sucessor nodes
Node::Edge::Edge(Node* p, Node* s) : predecessor(p), successor(s)
{
	this->visited = false;
}

// protected void Node::link(Node*, Node*)
// links a predecessor and successor Node together by
// giving them both an Edge conecting to one and other
void Node::link(Node* predecessor, Node* successor)
{
	predecessor->number_of_successors++;

	successor->number_of_predecessors++;

	Edge* edge = new Edge(predecessor, successor);

	predecessor->successors.push_back(edge);

	successor->predecessors.push_back(edge);
}

// public Node()
// default constructor for Nodes
Node::Node() : successors(), predecessors()
{
	this->contents = nullptr;
	
	this->number_of_successors = 0;

	this->number_of_predecessors = 0;
}

// public int Node::get_number_of_successors()
// returns the number of successors this Node has
int Node::get_number_of_successors()
{
	return this->number_of_successors;
}

// public int Node::get_number_of_predecessors()
// returns the number of predecessors this Node has
int Node::get_number_of_predecessors()
{
	return this->number_of_predecessors;
}

// public Tensor* Node::getContents()
// returns the Tensor contained within this Node
Tensor* Node::get_contents()
{
	return this->contents;
}

Shape Node::get_shape() 
{
	return this->contents->get_shape();
}

std::vector<Node*> Node::get_successor_nodes()
{
	std::vector<Node*> successors;

	for (unsigned int i = 0; i < this->number_of_successors; i++) 
	{
		successors.push_back(this->successors[i]->successor);
	}

	return successors;
}

std::vector<Node*> Node::get_predecessor_nodes() 
{
	std::vector<Node*> predecessors;

	for (unsigned int i = 0; i < this->number_of_predecessors; i++)
	{
		predecessors.push_back(this->predecessors[i]->predecessor);
	}

	return predecessors;
}

// public vector<Tensor*> Node::get_predecessor_tensor()
// returns vector of pointers to the tensors of this nodes predecessors
std::vector<Tensor*> Node::get_predecessor_tensors()
{
	std::vector<Tensor*> x;

	for (unsigned int i = 0; i < this->number_of_predecessors; i++)
	{
		x.push_back(this->predecessors[i]->predecessor->get_contents());
	}

	return x;
}

void Node::full_reset()
{
	this->clear();

	for (unsigned int i = 0; i < this->number_of_predecessors; i++)
	{
		this->predecessors[i]->visited = false;

		this->predecessors[i]->predecessor->full_reset();
	}
}