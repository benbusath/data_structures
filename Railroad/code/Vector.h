#ifndef VECTOR
#define VECTOR
#include <string>
#include "Deque.h"
using std::string;

template<typename T>
class Vector
{
private:
	Deque<size_t> vector;
public:
	void push_back(const T& value)
	{
		vector.push_back(value);
	}
	void pop_back()
	{
		vector.pop_back();
	}
	T& back()
	{
		return vector.back();
	}
	size_t size()
	{
		return vector.size();
	}
	T& at(size_t index)
	{
		return vector.at(index);
	}
	const string toString()
	{
		return vector.toString();
	}
};



#endif