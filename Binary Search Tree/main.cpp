#include "BST.h"
#include <fstream>
#include <string>
using std::endl;
using std::string;


#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif


int main(int argc, char* argv[])
{
	std::ifstream inFS;
	std::ofstream outFS;
	inFS.open(argv[1]);
	outFS.open(argv[2]);

	BST<int> tree;
	string command;
	int input;

	while (inFS >> command)
	{
		if (command == "Add")
		{
			outFS << "Add ";
			inFS >> input;
			outFS << input;

			if (tree.addNode(input))
				outFS << " True";
			else
				outFS << " False";

		}

		else if (command == "Remove")
		{
			outFS << "Remove ";
			inFS >> input;
			outFS << input;

			if (tree.removeNode(input))
				outFS << " True";
			else
				outFS << " False";

		}
		else if (command == "PrintBST")
		{
			outFS << "PrintBST";
			outFS << tree;
		}

		else if (command == "Find")
		{
			inFS >> input;
			if (tree.find(input))
				outFS << "Found";
			else
				outFS << "Not Found";
		}

		else if (command == "Clear")
		{
			outFS << "Clear ";
			
			if (tree.clearTree())

			outFS << "True";
		}

		else
		{ 
			outFS << "Unknown command";
		}


		outFS << endl;
	}

	VS_MEM_CHECK;
	return 0;
}