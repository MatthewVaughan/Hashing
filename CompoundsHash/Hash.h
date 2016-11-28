#include <string>
#include "List.h"

using namespace std;
#pragma once

const int TWENTYSIX = 26;

class Hash
{

private:
	int size = TWENTYSIX;
	Node* arr[TWENTYSIX];
	int getKey(string element);
	int convertToASCII(string temp);
	void printH(Node* temp);
	void InsertH(Node* temp, double weight, string element);
	double RetrieveH(Node* temp, string element);
	double operator[](string element);
	double getWeightParenthesis(string compound);

public:
	Hash();
	~Hash();
	void Insert(string element, double weight);
	void Print();
	double Retrieve(string element);
	double getWeight(string compound);
};

