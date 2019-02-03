#ifndef QS_H_
#define QS_H_
#include <string>
#include <sstream>
#include "QSInterface.h"
using namespace std;

template<typename T>
class QS : public QSInterface<T>
{
private:
	T * arr;
	size_t totalElements=0;
	size_t arrCapacity=0;
public:
	QS()
	{
		arr = NULL;
	}
	~QS(){}

	/** Dynamically allocate an initial array to the QuickSort class. */
	bool createArray(size_t capacity)
	{
		if (arr != NULL)
		{
			clear();
		}
		if (arr==NULL)
		{
			arr = new T[capacity];
			for (int i = 0; i < capacity; i++){ arr[i] = 0; }
			
			this->arrCapacity = capacity;
			return true;
		}
		
		return false;
	}

	/** Add an element to the QuickSort array. Dynamically grow array as needed. */
	bool addElement(T element)
	{
		if (arr == NULL) { return false; }
		
		if (totalElements == arrCapacity)
		{
			T * copy;
			copy = new T[arrCapacity * 2];

			for (int i = 0; i < arrCapacity; i++)
			{
				copy[i] = arr[i];
			}
			swap(arr, copy);
			arrCapacity *= 2;
			delete[] copy;
		}
		arr[totalElements] = element;
		totalElements++;
		
		return true;
	}

	/** Return size of the QuickSort array. */
	size_t capacity() const { return arrCapacity; }

	/** Return number of elements in the QuickSort array. */
	size_t size() const { return totalElements; }
	
	/** Removes all items from the QuickSort array. */
	bool clear()
	{
		if (arr != NULL)
		{
			arr = NULL;
			totalElements = 0;
			return true;
		}
		return false;
	}

	/** The median of three pivot selection has two parts:
	1) Calculates the middle index by averaging the given left and right indices:
	middle = (left + right)/2
	2) Then bubble-sorts the values at the left, middle, and right indices.

	After this method is called, data[left] <= data[middle] <= data[right].

	@param left - the left boundary for the subarray from which to find a pivot
	@param right - the right + 1 boundary for the subarray from which to find a pivot
	@return the index of the pivot (middle index).
	Return -1 if	1) the array is empty,
	2) if either of the given integers is out of bounds,
	3) or if the left index is not less than the right index.
	*/
	int medianOfThree(size_t left, size_t right)
	{
		size_t middle = (left + right) / 2;
		if (arr == NULL) { return -1; }
		if (left > right) { return -1; }
		else if ((right - left) <= 1)
		{
			if (arr[left] > arr[right - 1])
			{
				T temp = arr[left];
				arr[left] = arr[right - 1];
				arr[right - 1] = temp;
			}
			return middle;
		}

		int indices[] = { left, middle,right - 1 };
		int numExchanges;
		do
		{
			numExchanges = 0;
			for (int i = 1; i < 3; i++)
			{
				if (arr[indices[i]] < arr[indices[i - 1]])
				{
					T temp = arr[indices[i]];
					arr[indices[i]] = arr[indices[i - 1]];
					arr[indices[i - 1]] = temp;
					numExchanges++;
				}
			}
		} while (numExchanges != 0);

		
		

		return middle;
	}

	/** @return: comma delimited string representation of the array. */
	std::string toString() const
	{
		std::ostringstream outSS;
		for (int i = 0; i < totalElements; i++)
		{
			outSS << arr[i];
			if (i < (totalElements - 1))
			{
				outSS << ",";
			}
		}

		return outSS.str();
	}

	/** Partitions a subarray around a pivot value selected according
	to median-of-three pivot selection. Because there are multiple ways
	to partition a list, follow the algorithm on page 611.

	The values which are smaller than the pivot should be placed to the left of the pivot;
	the values which are larger than the pivot should be placed to the right of the pivot.

	@param left - left index for the subarray to partition.
	@param right - right index + 1 for the subarray to partition.
	@param pivotIndex - index of the pivot in the subarray.
	@return the pivot's ending index after the partition completes:
	Return -1 if	1) the array is empty,
	2) if any of the given indexes are out of bounds,
	3) if the left index is not less than the right index.
	*/
	int partition(size_t left, size_t right, size_t pivotIndex)
	{
		T up = left+1;
		T down = right - 1;

		swap(arr[left], arr[pivotIndex]);

		do
		{
			while ((up != right - 1) && !(arr[left] < arr[up])) up++;
			while (arr[left] < arr[down]) down--;
			if (up < down)
			{
				swap(arr[up], arr[down]);
			}
		} while (up < down);
		swap(arr[left], arr[down]);

		return down;
	}


	/** Sort the elements of a QuickSort subarray using median and partition functions. */
	virtual bool sort(size_t left, size_t right)
	{
		if (right - left == 1) {
			if (arr[right] > arr[left]) {
				return true;
			}
			else {
				swap(arr[right], arr[left]);
				return true;
			}
		}
		
		if (left < 0 || right > size() - 1 || right <= left || left > right) return false;

		size_t pivotIndex=medianOfThree(left, right);
		size_t newIndex=partition(left, right, pivotIndex);

		sort(left, newIndex-1);
		sort(newIndex+1, right);
		return true;
	}



	/** Sort all elements of the QuickSort array using median and partition functions. */
	virtual bool sortAll()
	{
		if(sort(0, size()-1)) return true;
		else return false;

	}
	/** Inserts toString in output stream **/
	friend std::ostream& operator<< (ostream& os, const QS<T>& quickSort)
	{
		os << quickSort.toString();
		return os;
	} // end operator<<
};

#endif 
