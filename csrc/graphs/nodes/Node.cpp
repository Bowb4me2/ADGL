#include "Node.h"
#include <typeinfo>

// public Node::Edge(Node*, Node*)
// constructor for edges with predecessor and sucessor nodes
Node::Edge::Edge(Node* p, Node* s) : predecessor(p), successor(s) 
{
	this->operation_completed = false;
}

// protected void Node::link(Node*, Node*)
// links a predecessor and successor Node together by
// giving them both an Edge conecting to one and other
void Node::link(Node* predecessor, Node* successor)
{
	predecessor->number_of_successors++;
	
	successor->number_of_predecessors++;

	predecessor->successors.push_back(new Edge(predecessor, successor));
	
	successor->predecessors.push_back(new Edge(successor, predecessor));
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

void Node::reset()
{
	for (unsigned int i = 0; i < this->number_of_predecessors; i++) 
	{
		this->predecessors[i]->operation_completed = false;
		this->predecessors[i]->predecessor->reset();
	}
}

void Node::full_reset()
{
	for (unsigned int i = 0; i < this->number_of_predecessors; i++)
	{
		this->predecessors[i]->operation_completed = false;
		this->predecessors[i]->predecessor->clear();
		this->predecessors[i]->predecessor->full_reset();
	}
}
