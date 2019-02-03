#ifndef DEQUE
#define DEQUE
#include <string>
#include <sstream>
#include "DequeInterface.h"
using std::string;
template<typename T>
class Deque : public DequeInterface<T>
{
private:
	static const size_t DEFAULT_CAPACITY = 4;
	size_t capacity;
	size_t numItems;
	size_t frontIndex;
	size_t rearIndex;
	T* data;

	void reallocate()
	{
		size_t new_capacity = 2 * capacity;
		T* new_data = new T[new_capacity];
		size_t j = frontIndex;
		for (size_t i = 0; i < numItems; i++)
		{
			new_data[i] = data[j];
			j = (j + 1) % capacity;
		}
		frontIndex = 0;
		rearIndex = numItems - 1;
		capacity = new_capacity;
		std::swap(data, new_data);

		delete[] new_data;
	}
public:
	Deque() 
	{
		capacity=DEFAULT_CAPACITY;
		numItems = 0;
		frontIndex = 0;
		rearIndex = DEFAULT_CAPACITY-1;
		data = new T[DEFAULT_CAPACITY];
	}
	~Deque(){}

	void push_front(const T& value)
	{
		if (numItems == capacity)
		{
			reallocate();
		}
		if (frontIndex == 0)
		{
			frontIndex = capacity - 1;
		}
		else
		{
			frontIndex--;
		}
		numItems++;
		
		data[frontIndex] = value;
	}
	void push_back(const T& value)
	{
		if (numItems == capacity)
		{
			reallocate();
		}
		
		rearIndex = (rearIndex + 1) % capacity;
		
		numItems++;
		data[rearIndex] = value;
	}

	void pop_front()
	{
		frontIndex = (frontIndex + 1) % capacity;
		numItems--;
	}
	void pop_back()
	{
		rearIndex = (rearIndex - 1) % capacity;
		numItems--;
	}
	T& front() { return data[frontIndex]; }
	T& back() { return data[rearIndex]; }
	T& at(size_t index) { return data[(frontIndex+index)%capacity]; }
	size_t size() const { return numItems; }
	bool empty() const { return numItems == 0; }
	string toString() const 
	{  
		
		std::ostringstream outSS;
		for (size_t i = 0; i < size(); i++)
		{
			outSS << data[(frontIndex+i)%capacity] << " ";
		}
		return outSS.str();
	}
};


#endif