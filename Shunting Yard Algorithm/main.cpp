#include <fstream>
#include <iostream>
#include <string>
#include "ExpressionManager.h"
#include <vector>
#include <stack>
#include<iomanip>
#include<sstream>
#include <iterator>
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif
using namespace std;
using std::vector;
using std::ostream;
using std::string;
using std::stringstream;


bool isBracket(string& token)
{
	if (token == "(" || token == "{" || token == "[" || token == ")"
		|| token == "}" || token == "]") return true;
	else return false;
}
bool isBalanced(string expression)
{
	stack<string> stack;
	istringstream ss(expression);
	istream_iterator<string> begin(ss), end;
	vector<string> tokens(begin, end);

	for (int i = 0; i < tokens.size(); i++)
	{

		string token = tokens.at(i);
		if (isBracket(token))
		{
			if (stack.empty())
			{
				stack.push(token);
			}
			else if (token == ")")
			{
				if (stack.top() == "(")
				{
					stack.pop();
					continue;
				}
				else { return false; };

			}
			else if (token == "}")
			{
				if (stack.top() == "{")
				{
					stack.pop();
					continue;
				}
				else { return false; };

			}
			else if (token == "]")
			{
				if (stack.top() == "[")
				{
					stack.pop();
					continue;
				}
				else { return false; };
			}

			else { stack.push(token); };
		}
	}

	if (stack.empty()) { return true; }
	else { return false; };
}
bool isValid(string expression)
{
	stack<string> stack;
	istringstream ss(expression);
	istream_iterator<string> begin(ss), end;
	vector<string> tokens(begin, end);

	for (int i = 0; i < tokens.size(); i++)
	{
		string tk = tokens.at(i);
		if (isBracket(tk) == false && (tk != "*") && (tk != "/") && (tk != "%") && (tk != "+")
			&& (tk != "-") && (isdigit(tk[0]) == false))
		{
			return false;
		}
	}

	int operandCount=0;
	int operatorCount=0;
	for (int i = 0; i < tokens.size(); i++)
	{
		string tk = tokens.at(i);
		if (isdigit(tk[0])) { operandCount++; }
		else if ((tk == "*") || (tk == "/") || (tk == "%") || (tk == "+") || (tk == "-"))
		{
			operatorCount++;
		}
	}
	if (operandCount != operatorCount + 1) { return false; }
	else return true;
}
int  precedence(string t)
{
	if (t == ")" || t == "}" || t == "]")
	{
		return 3;
	}
	else if (t == "*" || t == "/" || t == "%")
	{
		return 2;
	}
	else if (t == "+" || t == "-")
	{
		return 1;
	}
	else if (t == "(" || t == "{" || t == "[")
	{
		return 0;
	}
}
string postfix(string expression)
{
	
	if (isValid(expression) == false) { return "Caught exception:  NOT Infix"; }
	if (isBalanced(expression) == false) { return "Caught exception: Expression is not balanced"; }


	stack<string> stack;
	istringstream ss(expression);
	istream_iterator<string> begin(ss), end;
	vector<string> tokens(begin, end);
	vector<string> output;



	for (int i = 0; i < tokens.size(); i++)
	{
		string token = tokens.at(i);
		
		if (isdigit(token[0]))
		{
			output.push_back(token);
		}
		else if (stack.empty())
		{
			stack.push(token);
		}
		else if (precedence(token) == 0)
		{
			stack.push(token);
		}
		else if (token == ")")
		{
			while (1)
			{
				if (stack.top() == "(") { stack.pop(); break; }
				else
				{
					output.push_back(stack.top());
					stack.pop();
				}
			}
		}
		else if (token == "}")
		{
			while (1)
			{
				if (stack.top() == "{") { stack.pop(); break; }
				else
				{
					output.push_back(stack.top());
					stack.pop();
				}
			}
		}
		else if (token == "]")
		{
			while (1)
			{
				if (stack.top() == "[") { stack.pop(); break; }
				else
				{
					output.push_back(stack.top());
					stack.pop();
				}
			}
		}
		else if (precedence(token) > precedence(stack.top()))
		{
			stack.push(token);
		}
		else if (precedence(token) <= precedence(stack.top()))
		{
			while (stack.empty()==false)
			{
				if (precedence(token) <= precedence(stack.top()))
				{
					output.push_back(stack.top());
					stack.pop();
				}
				else if (precedence(token) > precedence(stack.top()))
				{
					break;
				}
				
			}
			stack.push(token);
		}
	}

	if (stack.empty() == false)	//empty remaining stack elements into output
	{
		for (int i = 0; i < stack.size()+1; i++)
		{
			output.push_back(stack.top());
			stack.pop();
		}
	}
	string postfix;
	for (int i = 0; i<output.size(); i++) //convert to string
	{
		postfix += output.at(i);
		postfix += " ";
	}
	return postfix;
}
int value(string expression)
{
	string express = postfix(expression);
	int value = 0;
	stack<int> stack;
	istringstream ss(express);
	istream_iterator<string> begin(ss), end;
	vector<string> tokens(begin, end);
	vector<string> output;

	for (int i = 0; i < tokens.size(); i++)
	{
		string token = tokens.at(i);
		if (isdigit(token[0]))
		{
			int num = 0;
			num = atoi(token.c_str());
			stack.push(num);
		}
		else
		{
			if (stack.size() >= 2)
			{
				if (token == "*")
				{

					int right = stack.top();
					stack.pop();
					int left = stack.top();
					stack.pop();

					int value = left*right;
					stack.push(value);
				}
				else if (token == "/")
				{
					int right = stack.top();
					stack.pop();
					int left = stack.top();
					stack.pop();

					int value = left / right;
					stack.push(value);
				}
				else if (token == "+")
				{
					int right = stack.top();
					stack.pop();
					int left = stack.top();
					stack.pop();

					int value = left + right;
					stack.push(value);
				}
				else if (token == "-")
				{
					int right = stack.top();
					stack.pop();
					int left = stack.top();
					stack.pop();

					int value = left - right;
					stack.push(value);
				}
				else if (token == "%")
				{
					int right = stack.top();
					stack.pop();
					int left = stack.top();
					stack.pop();

					int value = left % right;
					stack.push(value);
				}
			}
		}
		
	}
	return stack.top();
}

int main(int argc, char* argv[])
{
	VS_MEM_CHECK
	ifstream inFS;
	ofstream outFS;
	string expression;
	string flag;
	stack <string> operatorStack;
	
	int digitData;
	
	inFS.open(argv[1]);
	outFS.open(argv[2]);
	
	while (inFS >> flag)
	{
		getline(inFS, expression);
		stack<string> balancedStack;
		istringstream ss(expression);
		istream_iterator<string> begin(ss), end;
		vector<string> tokens(begin, end);
		ExpressionManager manager(expression);
		
		outFS << "Expression: " << expression<<endl;
		outFS << "Infix: " << manager.infix()<<endl;
		if ((manager.infix()) != "Infix: Caught exception: NOT Infix")
		{
			outFS <<"Postfix: "<< manager.postfix()<<endl;
			outFS << "Prefix: " << endl;
			outFS << "Value: " << manager.value() << endl;
		}
		





		//cout << postfix("40 * { 2 + 4 - ( 2 + 2 ) } - 4 / 5 / 6")<<endl;
		//system("pause");
		//cout << postfix(expression)<<endl;
		//system("pause");
		//cout << value(expression) << endl;
		outFS << endl;
	}
	
	
	return 0;
}