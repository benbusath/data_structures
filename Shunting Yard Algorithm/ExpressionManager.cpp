#include <fstream>
#include <iostream>
#include <string>
#include "ExpressionManager.h"
#include <vector>
#include <stack>
#include<sstream>
#include <iterator>
using namespace std;

ExpressionManager::ExpressionManager(string exp)
{
	expression = exp;
}

bool ExpressionManager::isBracket(string& token)
{
	if (token == "(" || token == "{" || token == "[" || token == ")"
		|| token == "}" || token == "]") return true;
	else return false;
}

bool ExpressionManager::isBalanced(string expression)
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

bool ExpressionManager::isValid(string expression)
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

	int operandCount = 0;
	int operatorCount = 0;
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

int  ExpressionManager::precedence(string t)
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

string ExpressionManager::postfix()
{

	


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
			while (stack.empty() == false)
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
		for (int i = 0; i < stack.size() + 1; i++)
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

string ExpressionManager::infix()
{
	if (isValid(expression)==true)
	{
		if (isBalanced(expression) == true)
		{
			return expression;
		}
	}
	else return "Infix: Caught exception: NOT Infix";
}

int ExpressionManager::value()
{

	{
		string express = postfix();
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
}