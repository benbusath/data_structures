#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
#include "Station.h"
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char* argv[])
{
	ifstream inFS;
	ofstream outFS;
	inFS.open(argv[1]);
	outFS.open(argv[2]);
	string option;
	Station<size_t> station;
	size_t data;
	for (string line; getline(inFS, line);)
	{
		if (line.find(':') == string::npos)
		{
			continue;
		}
		outFS << line << " ";
		option = line.substr(0, line.find(':'));
		if (option == "Add")
		{
			if (line.find("station") != string::npos)
			{
				line = line.substr(line.find(' ') + 1);
				istringstream iSS(line);
				iSS >> data;
				outFS << station.addCar(data);
			}
			else if (line.find("queue") != string::npos)
			{
				outFS << station.addQueue();
			}
			else if (line.find("stack") != string::npos)
			{
				outFS << station.addStack();
			}

		}



		else if (option == "Remove")
		{
			if (line.find("station") != string::npos)
			{
				outFS<<station.removeCar();
			}
			else if (line.find("queue") != string::npos)
			{
				outFS << station.removeQueue();
			}
			else if (line.find("stack") != string::npos)
			{
				outFS << station.removeStack();
			}
		}
		else if (option == "Top")
		{
			if (line.find("station") != string::npos)
			{
				outFS << station.topCar();
			}
			else if (line.find("queue") != string::npos)
			{
				outFS << station.topQueue();
			}
			else if (line.find("stack") != string::npos)
			{
				outFS << station.topStack();
			}
		}

		else if (option == "Size")
		{
			if (line.find("queue") != string::npos)
			{
				outFS << station.sizeQueue();
			}
			else if (line.find("stack") != string::npos)
			{
				outFS << station.sizeStack();
			}
		}
		else if (option == "Find")
		{
			line = line.substr(line.find(':') + 1);
			istringstream iSS(line);
			iSS >> data;
			outFS << station.find(data);
		}
		else if (option == "Train")
		{
			outFS << station.showTrain();
		}
		outFS << endl;
	}


	

	VS_MEM_CHECK
		return 0;
}