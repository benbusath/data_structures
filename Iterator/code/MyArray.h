#ifndef MYARRAY_H
#define MYARRAY_H
#include <map>
#include <string>
enum myMode { SEQUENTIAL, PRIME, COMPOSITE, FIB };
#define MAX_ARRAY_SIZE	1000
#include <iterator>
#include <vector>
#include <cmath>


template<typename T>
class MyArray
{
private:
	int size;
	T* vec;
public:
	void myArray() 
	{
		size = 0;
		vec = (T*)malloc(MAX_ARRAY_SIZE * sizeof(T));
		return;
	};
	void push_back(T item) { vec[size++] = item; return; };
	class Iterator
	{
	private:
		int index;
		T* vec;
	public:
		Iterator(T* vec)
		{ 
			this->vec = vec;
		}
		Iterator(T* vec, int size) 
		{ 
			this->vec = vec;
			this->size=size; 
		}
		Iterator(T* vec, int size, int pointer)
		{
			this->vec = vec; 
			this->size = size;
			this->index = index;
		}
		Iterator(T* vec, int size, int index, int mode) 
		{
			this->vec = vec;
			this->size = size;
			this->index = index;
			myMode = mode;
		}
		bool operator!=(const Iterator& other) const 
		{
			index != other.index;
		};
		Iterator& operator+=(int i) { index += i; };
		Iterator& operator++() 
		{ 
			bool isPrime()
			{
				for (unsigned int i = 2; i <= sqrt(vec[index]); i++) {
					if (static_cast<int>(sqrt(vec[index])) % i == 0) {
						return false;
					}
				}
				return true;
			}
			bool isFib()
			{
				if (index < 2)
				{
					return false;
				}
				else if (vector[index] == (vector[index - 2] + vector[index - 1]))
				{
					return true;
				}
				return false;
			}
			myMode mode;
				index++;
				switch (mode) {
				case 1:
					for (index; index < size; index++)
					{
						if (isPrime())
						{
							break;
						}
					}
					break;
				case 2:
					for (index; index < size; index++)
					{
						if (!isPrime())
						{
							break;
						}
					}
					break;
				case 3:
					for (index; index < size; index++)
					{
						if (isFib())
						{
							break;
						}
					}
					break;
				default:
					break;
				}
		};
		T& operator*() const 
		{ 
			return vec[index]; 
		};
		T& operator[](int i) const { return vec[index+i]; };
		std::string toString() const 
		{
			ostringstream outSS;
			outSS << "size=" << size << " index=" << index << " mode=" << mode;
			return outSS.str();
		};
		friend std::ostream& operator<< (std::ostream& os, const Iterator& iter) { os << iter.toString(); return os; };
	};
	Iterator begin() { return MyArray<T>::Iterator(vec); }
	bool isPrime(int number)
	{
		int i;
		if (number < 2) return false;
		for (i = 2; i < number; i++)
		{
			if (number % i == 0) return false;
		}
		return true;
	}
	Iterator begin(myMode mode) 
	{
	
	}
	Iterator end()
	{ 
		Iterator it(vec, size, 0, size); 
		return 0;
	}
	std::string toString() const 
	{ 
		ostringstream outSS;
		outSS << "size=" << size << " index=" << index << " mode=" << mode;
		return outSS.str();
	};
	friend std::ostream& operator<< (std::ostream& os, const MyArray<T>& myArray) 
	{
		os << myArray.toString();
		return os;
	};

};
#endif // MYARRAY_H