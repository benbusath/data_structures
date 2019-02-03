#ifndef STATION
#define STATION
#include "Deque.h"
#include "Vector.h"
#include "Queue.h"
#include "Stack.h"
#include <string>
#include <sstream>
using std::string;
using std::ostringstream;
template<typename T>
class Station
{
private:
	Vector<T> train;
	Stack<T> stack;
	Queue<T> queue;
	T turnTableCar;
	bool empty;
public:
	Station() { empty = true; }
	string addCar(T value)
	{
		if (empty==true)
		{
			turnTableCar = value;
			empty = false;
			return "OK";
		}
		else
			return "Turntable occupied!";
	}
	string removeCar()
	{
		if (empty == false)
		{
			train.push_back(turnTableCar);
			empty = true;
			return "OK";
		}
		else
			return "Turntable empty!";
	}
	string topCar()
	{
		if (empty == false)
		{
			std::ostringstream outSS;
			outSS << turnTableCar;
			return outSS.str();
		}
		else return "Turntable empty!";
	}
	string addStack()
	{
		if (empty == false)
		{
			stack.push(turnTableCar);
			empty = true;
			return "OK";
		}
		else return "Turntable empty!";
	}
	string removeStack()
	{
		if (empty==true) 
		{
			turnTableCar = stack.top();
			stack.pop();
			empty = false;
			return "OK";
		}
		else return "Turntable occupied!";
	}
	string topStack()
	{
		if (stack.size()>0)
		{
			std::ostringstream outSS;
			outSS << stack.top();
			return outSS.str();
		}
		else return "Stack empty!";
	}
	string addQueue()
	{
		if (empty == false)
		{
			queue.push(turnTableCar);
			empty = true;
			return "OK";
		}
		else return "Turntable empty!";
	}
	string removeQueue()
	{
		if (empty)
		{
			turnTableCar = queue.top();
			queue.pop();
			empty = false;
			return "OK";
		}
		else return "Turntable occupied!";
	}
	string topQueue()
	{
		if (queue.size()>0)
		{
			std::ostringstream outSS;
			outSS << queue.top();
			return outSS.str();
		}
		else return "Queue empty!";
	}
	size_t sizeQueue()
	{
		return queue.size();
	}
	size_t sizeStack()
	{
		return stack.size();
	}
	string find(T car)
	{
		
		if (turnTableCar == car)
		{
			return "Turntable";
		}
		for (size_t i = 0; i < queue.size(); i++)
		{
			if (queue.at(i) == car)
			{
				ostringstream outSS;
				outSS << "Queue[" << i << "]";
				return outSS.str();
			}
		}
		for (size_t i = 0; i < stack.size(); i++)
		{
			if (stack.at(i) == car)
			{
				ostringstream outSS;
				outSS << "Stack[" << i << "]";
				return outSS.str();
			}
		}
		for (size_t i = 0; i < train.size(); i++)
		{
			if (train.at(i) == car)
			{
				ostringstream outSS;
				outSS << "Train[" << i << "]";
				return outSS.str();
			}
		}
		return "Not Found!";
	}

	string showTrain()
	{
		ostringstream outSS;
		outSS << "Train: "<<train.toString();
		return outSS.str();
	}
	
};


#endif