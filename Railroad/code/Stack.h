#ifndef STACK
#define STACK
#include <string>
#include "Deque.h"
using std::string;

template<typename T>
class Stack
{
private:
	Deque<size_t> queue;
public:
	void push(const T& value)
	{
		queue.push_back(value);
	}
	void pop()
	{
		queue.pop_back();
	}
	T& top()
	{
		return queue.back();
	}
	size_t size()
	{
		return queue.size();
	}
	T& at(size_t index)
	{
		return queue.at(index);
	}
	const string toString()
	{
		return queue.toString();
	}
};



#endif