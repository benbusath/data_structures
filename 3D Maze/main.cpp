#include <string>
#include<fstream>
#include<sstream>
#include <iostream>
#include <string>
#include "Maze.h"
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif
using std::endl;
using std::string;
using std::cout;

int main(int argc, char* argv[])
{
	std::ofstream outFS;
	std::ifstream inFS;
	inFS.open(argv[1]);
	outFS.open(argv[2]);




	Maze mazey(inFS);
	outFS << "Solve Maze:" << endl;
	outFS << mazey.toString();

	outFS << "Solution:" << endl;
	if (mazey.find_maze_path())
		outFS << mazey.toString();
	else
		outFS << "No solution!" << endl;
	

	
	VS_MEM_CHECK;
	return 0;
}