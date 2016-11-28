#include "Node.h"



Node::Node(double temp, int keyTemp)
{
	data = temp;
	keyASC = keyTemp;
	next = nullptr;
}


Node::~Node()
{
}
