#pragma once
struct Node
{
	double data;
	int keyASC;
	Node* next;

	Node(double temp, int keyTemp);
	~Node();
};

