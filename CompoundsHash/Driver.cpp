#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Hash.h"

using namespace std;

int main()
{
	Hash browns;
	ifstream myReadElementsFile;
	myReadElementsFile.open("PeriodicTableElements.txt");
	if (myReadElementsFile.fail())
	{
		cout << "Could not open the PeriodicTableElements file" << endl;
	}
	string outputElements;
	if (myReadElementsFile.is_open())
	{
		while (!myReadElementsFile.eof())
		{
			string elementsName;
			double weight;

			myReadElementsFile >> outputElements;
			cout << outputElements;
			elementsName = outputElements;

			myReadElementsFile >> outputElements;
			cout << " " << outputElements << endl;
			weight = stod(outputElements);

			browns.Insert(elementsName, weight);
		}
		browns.Print();
	}

	ifstream myReadCompoundsFile;
	myReadCompoundsFile.open("formulas.txt");
	if (myReadCompoundsFile.fail())
	{
		cout << "Could not open the Compounds file" << endl;
	}
	string outputCompounds;
	if (myReadCompoundsFile.is_open())
	{
		while (!myReadCompoundsFile.eof())
		{
			myReadCompoundsFile >> outputCompounds; 
			cout << "\n" << outputCompounds << " = " << browns.getWeight(outputCompounds)<< endl;
		}
	}
	system("PAUSE");
	return 0;
}