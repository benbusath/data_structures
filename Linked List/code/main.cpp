#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;

namespace integer {int data;}

namespace strng { string data; }
int main(int argc, char* argv[])
{
	ifstream inFS;
	ofstream outFS;
	inFS.open(argv[1]);
	outFS.open(argv[2]);
	LinkedList<int>* intList;
	LinkedList<string>* stringList;

		string input;
		string command;
		inFS >> command;
		


		
	if(command=="INT")
	{
		using  integer::data;
		outFS << command;
		outFS << " [INT]" << endl;
			
		intList = new LinkedList<int>();
		while (inFS >> command)
		{
			if (command == "insertHead")
			{
				outFS << command<<" ";
				inFS >> data;
				outFS <<data<<" ";
				bool result=intList->insertHead(data);

				if (result == true) { outFS << "true"; }
				else if (result == false) { outFS << "false"; }
			}
			else if (command == "insertTail")
			{
				outFS << command << " ";
				inFS >> data;
				outFS << data << " ";
				bool result=intList->insertTail(data);

				if (result == true) { outFS << "true"; }
				else if (result == false) { outFS << "false"; }
			}
			else if (command == "insertAfter")
			{
				int toFind;
				int toAdd;
				outFS << command << " ";
				inFS >> data;
				outFS << data << " ";
				toFind = data;
				inFS >> data;
				outFS << data << " ";
				toAdd = data;
				bool result=intList->insertAfter(toFind, toAdd);

				if (result == true) { outFS << "true"; }
				else if (result == false) { outFS << "false"; }
			}
			else if (command == "size")
			{
				outFS << command<<" ";
				outFS << intList->size();
			}
			else if (command == "at")
			{
				int index;
				outFS << command << " ";
				inFS >> index;
				outFS << index << " ";
				outFS << intList->at(index);
			}
			else if (command == "remove")
			{
				outFS << command<<" ";
				inFS >> data;
				outFS << data;
				intList->remove(data);
			}
			else if (command == "clear")
			{
				outFS << "command";
				intList->clear();
			}
			else if (command == "printList")
			{
				outFS << "printList ";
				outFS << intList->toString();
			}
			outFS << endl;
		}
	}














	if (command == "STRING")
	{
		using  strng::data;
		outFS << command;
		outFS << " [STRING]" << endl;

		stringList = new LinkedList<string>();
		while (inFS >> command)
		{
			if (command == "insertHead")
			{
				outFS << command << " ";
				inFS >> data;
				outFS << data << " ";
				bool result = stringList->insertHead(data);

				if (result == true) { outFS << "true"; }
				else if (result == false) { outFS << "false"; }
			}
			else if (command == "insertTail")
			{
				outFS << command << " ";
				inFS >> data;
				outFS << data << " ";
				bool result = stringList->insertTail(data);

				if (result == true) { outFS << "true"; }
				else if (result == false) { outFS << "false"; }
			}
			else if (command == "insertAfter")
			{
				string toFind;
				string toAdd;
				outFS << command << " ";
				inFS >> data;
				outFS << data << " ";
				toFind = data;
				inFS >> data;
				outFS << data << " ";
				toAdd = data;
				bool result = stringList->insertAfter(toFind, toAdd);

				if (result == true) { outFS << "true"; }
				else if (result == false) { outFS << "false"; }
			}
			else if (command == "size")
			{
				outFS << command << " ";
				outFS << stringList->size();
			}
			else if (command == "at")
			{
				
				int index;
				outFS << command << " ";
				inFS >> index;
				outFS << index << " ";
				try 
				{
					outFS << stringList->at(index);
				}
				catch (invalid_argument&)
				{
				}
			}
			else if (command == "remove")
			{
				outFS << command << " ";
				inFS >> data;
				outFS << data;
				bool result = stringList->remove(data);
				if (result == true) { outFS << "true"; }
				else if (result == false) { outFS << "false"; }
			}
			else if (command == "clear")
			{
				outFS << "command";
				stringList->clear();
			}
			else if (command == "printList")
			{
				outFS << "printList ";
				outFS << stringList->toString();
			}
			outFS << endl;
		}
	}

}