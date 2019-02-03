#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H
#include <ostream>
#include <string>
#include <vector>
#include "ExpressionManagerInterface.h"
using std::string;
using std::ostream;
using std::vector;


class ExpressionManager : public ExpressionManagerInterface
{
private:
	string expression;
public:
	ExpressionManager(string exp);
	~ExpressionManager() {};
	
	/*Determines whether an infix expression is balanced*/
	bool isBalanced(string expression);

	/*Returns whether token is a bracket or not*/
	bool isBracket(string& token);

	/*Returns the precedence of an operator*/
	int precedence(string t);

	/*Determines validity of an infix expression*/
	bool isValid(string expression); 
	


	int value(); /** Return the integer value of the infix expression */

	string infix(); /** Return the infix expression / rejects invald */

	/*Converts an infix to postfix expression*/
	string postfix();

	//didn't end up using toString function
	string toString() const { return ""; } 
};
#endif // EXPRESSION_MANAGER_H
