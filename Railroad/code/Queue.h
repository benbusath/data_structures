#ifndef QUEUE
#define QUEUE
#include <string>
#include "Deque.h"
using std::string;

template<typename T>
class Queue
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
		queue.pop_front();
	}
	T& top()
	{
		return queue.front();
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