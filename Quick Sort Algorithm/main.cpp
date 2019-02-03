#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include "QS.h"

int main(int argc, char* argv[])
{
	QS<int> quick;
	ifstream inFS;
	ofstream outFS;
	inFS.open(argv[1]);
	outFS.open(argv[2]);



	/*
	cout << quick << endl;
	cout << quick.capacity() << endl;
	cout << quick.size() << endl;

	quick.clear();
	quick.createArray(4);
	for(int i=0;i<10;i++)
	{
		quick.addElement(i);
	}
	cout << quick << endl << quick.capacity() << endl;
	*/

	

	string command;
	while (inFS >> command)
	{
		if (command == "QuickSort")
		{
			outFS << "QuickSort ";
			int capacity;
			inFS >> capacity;
			outFS << capacity;
			if (quick.createArray(capacity)) { outFS << " OK"; }

		}
		if (command == "AddToArray")
		{
			outFS << "AddToArray ";
			int element;
			bool fail = false;
			getline(inFS, command);
			ostringstream oss;
			istringstream iss(command);
			while (iss >> element)
			{
				oss << element << ",";
				quick.addElement(element);
			}
			string output = oss.str();
			output = output.substr(0, output.size() - 1);
			outFS << output;
			outFS << " Ok";
			
		}
		if (command == "Capacity")
		{
			outFS << "Capacity ";
			outFS << quick.capacity();
		}
		if (command == "Size")
		{
			outFS << "Size ";
			outFS << quick.size();
		}
		if (command == "Clear")
		{
			outFS << "Clear ";
			quick.clear();
			outFS << "OK";
		}
		if (command == "Sort")
		{
			outFS << "Sort ";
			int left, right;
			inFS >> left;
			outFS << left << ",";
			inFS >> right;
			outFS << right;
			if (quick.sort(left, right)) { outFS << " OK"; }
			else outFS << " ERROR";
		}
		if (command == "MedianOfThree")
		{
			outFS << "MedianOfThree ";
			int left, right;
			inFS >> left;
			outFS << left<<",";
			inFS >> right;
			outFS << right << " = ";
			outFS << quick.medianOfThree(left, right);
		}
		if (command == "SortAll")
		{
			outFS << "SortAll ";
			if (quick.sortAll()) { outFS << "OK"; }
			else outFS << "ERROR";
		}
		if (command == "Partition")
		{
			outFS << "Partition ";
			int left, right, pivot;
			inFS >> left;
			outFS << left << ",";
			inFS >> right;
			outFS << right << ",";
			inFS >> pivot;
			outFS << pivot << " = ";
			outFS << quick.partition(left, right,pivot);
		}
		if (command == "PrintArray")
		{
			outFS << "PrintArray ";
			outFS << quick;
		}
		outFS << endl;
	}
	VS_MEM_CHECK;
	return 0;
}