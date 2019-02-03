#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "myArray.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

/*********************************************************************
*********************************************************************/
int main(int argc, char * argv[])
{
	ifstream inFS;
	inFS.open(argv[1]);
	VS_MEM_CHECK;

	MyArray<int> numbers;
	numbers.myArray();
	std::ostream& out = std::cout;
	
	for (string line; getline(inFS, line);)
	{
		int element;
		inFS >> element;
		numbers.push_back(element);
	}

	out << numbers << endl << endl;

	out << "SEQUENTIAL" << endl;
	MyArray<int>::Iterator iter1 = numbers.begin();
	out << "iter1: " << iter1 << endl;
	for (; iter1 != numbers.end(); ++iter1)
		out << *iter1 << ' ';
	out << endl << endl;

	out << "PRIME" << endl;
	MyArray<int>::Iterator iter2 = numbers.begin(PRIME);
	out << "iter2: " << iter2 << endl;
	for (; iter2 != numbers.end(); ++iter2)
		out << *iter2 << ' ';
	out << endl << endl;

	out << "COMPOSITE" << endl;
	MyArray<int>::Iterator iter3 = numbers.begin(COMPOSITE);
	out << "iter3: " << iter3 << endl;
	for (; iter3 != numbers.end(); ++iter3)
		out << *iter3 << ' ';
	out << endl << endl;

	out << "FIBINOCCI" << endl;
	MyArray<int>::Iterator iter4 = numbers.begin(FIB);
	out << "iter4: " << iter4 << endl;
	for (; iter4 != numbers.end(); ++iter4)
		out << *iter4 << "=" << iter4[-2] << "+" << iter4[-1] << ' ';
	out << endl << endl;

	return 0;
}