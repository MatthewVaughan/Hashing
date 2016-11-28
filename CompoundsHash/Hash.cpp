#define _USE_MATH_DEFINES
#include "Hash.h"
#include <math.h>
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <string>
using namespace std;

Hash::Hash()
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = nullptr;
	}
}


Hash::~Hash()
{
}

int Hash::getKey(string element)
{
	int hash = toupper(element[0]) - 'A';
	return hash % size;
}

int Hash::convertToASCII(string temp)
{
	int total = 0;
	for (int i = 0; i < temp.length(); i++)
	{
		char x = temp.at(i);
		total = total + int(x);
	}
	return total;
}

void Hash::InsertH(Node* temp, double weight, string element)
{
	if (temp->next == nullptr)
	{
		Node* NewNode = new Node(weight, convertToASCII(element));
		temp->next = NewNode;
	}
	else
	{
		InsertH(temp->next, weight, element);
	}
}

void Hash::Insert(string element, double weight)
{
	if (arr[getKey(element)] == NULL)
	{
		Node* NewNode = new Node(weight, convertToASCII(element));
		arr[getKey(element)] = NewNode;
	}
	else
	{
		InsertH(arr[getKey(element)], weight, element);
	}
}

void Hash::printH(Node* temp)
{
	if (temp == nullptr)
	{
		return;
	}
	else
	{
		cout << temp->data << endl;
		printH(temp->next);
	}
}

void Hash::Print()
{
	for (int i = 0; i < size; i++)
	{
		printH(arr[i]);
	}
}

double Hash::getWeightParenthesis(string compound)
{
	double total = 0;
	for (int i = 0; i < compound.length(); i++)
	{
		stringstream ss;
		if (isupper(compound[i]))
		{
			if (i < compound.length())
			{
				if (islower(compound[i + 1]))
				{
					string element;
					ss << compound[i] << compound[i + 1];
					ss >> element;
					i++;

					if (isdigit(compound[i + 1]))
					{
						total = total + Retrieve(element) * compound[i];
						i++;
					}

					else
					{
						total = total + Retrieve(element);
					}
				}

				else if (isdigit(compound[i + 1]))
				{
					string element;
					ss << compound[i];
					ss >> element;
					char temp = compound[i + 1];
					int multiplier = temp - '0';
					total = total + Retrieve(element) * multiplier;
				}

				else
				{
					string element;
					ss << compound[i];
					ss >> element;
					total = total + Retrieve(element);
				}
			}
			else
			{
				string element;
				ss << compound[i];
				ss >> element;
				total = total + Retrieve(element);
			}
		}
		ss << "";
	}
	return total;
}

double Hash::getWeight(string compound)
{
	
	double total = 0;
	for (int i = 0; i < compound.length(); i++)
	{
		stringstream ss;
		if (compound[i] == '(')
		{
			i++;
			string element = "";
			while (compound[i] != ')')
			{
				ss << compound[i];
				i++;
			}
			ss >> element;
			total = total + getWeightParenthesis(element);
			i++;

			if (isdigit(compound[i]))
			{
				char temp = compound[i];
				int multiplier = temp - '0';
				total = total * multiplier;
			}
		}
		if (isupper(compound[i]))
		{
			if (i < compound.length())
			{
				if (islower(compound[i + 1]))
				{
					string element;
					ss << compound[i] << compound[i + 1];
					ss >> element;
					i++;

					if (isdigit(compound[i + 1]))
					{
						char temp = compound[i + 1];
						int multiplier = temp - '0';
						total = total + Retrieve(element) * multiplier;
						i++;
					}

					else
					{
						total = total + Retrieve(element);
					}
				}

				else if (isdigit(compound[i + 1]))
				{
					string element;
					ss << compound[i];
					ss >> element;
					char temp = compound[i+1];
					int multiplier = temp - '0';
					total = total + Retrieve(element) * multiplier;
					i++;
				}

				else
				{
					string element;
					ss << compound[i];
					ss >> element;
					total = total + Retrieve(element);
				}
			}
			else
			{
				string element;
				ss << compound[i];
				ss >> element;
				total = total + Retrieve(element);
			}
		}
		ss << "";
	}
	return total;
}

double Hash::RetrieveH(Node* temp, string element)
{
	if (convertToASCII(element) == temp->keyASC)
	{
		return temp->data;
	}
	else
	{
		return RetrieveH(temp->next, element);
	}

}

double Hash::Retrieve(string element)
{
	if (arr[getKey(element)]->keyASC == convertToASCII(element))
	{
		return arr[getKey(element)]->data;
	}
	else
	{
		return RetrieveH(arr[getKey(element)], element);
	}
}

double Hash::operator[](string element)
{
	return Retrieve(element);
}