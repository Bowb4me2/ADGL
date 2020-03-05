#ifndef __NODE_H__
#define __NODE_H__
#include "../../tensor/Tensor.h"
#include <vector>

class Node
{
private:

protected:

	class Edge
	{
	public:

		Edge(Node* p, Node* s);

		bool visited;

		Node* predecessor;

		Node* successor;
	};

	Tensor* contents;

	unsigned int number_of_successors;

	unsigned int number_of_predecessors;

	std::vector<Edge*> successors;

	std::vector<Edge*> predecessors;

public:

	static void link(Node* predecessor, Node* successor);

	Node();

	int get_number_of_successors();

	int get_number_of_predecessors();

	Tensor* get_contents();

	Shape get_shape();

	std::vector<Node*> get_successor_nodes();

	std::vector<Node*> get_predecessor_nodes();

	std::vector<Tensor*> get_predecessor_tensors();

	virtual void reset() = 0;

	void full_reset();

	virtual void init() = 0;

	virtual void clear() = 0;

	virtual void forward() = 0;

	virtual void backward() = 0;

	virtual void add_grad(Tensor* grad) = 0;
};

#endif
