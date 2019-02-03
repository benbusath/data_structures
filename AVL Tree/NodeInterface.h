#ifndef NODEINTERFACE_H_
#define NODEINTERFACE_H_

#include <iostream>

using namespace std;

template<class T>
class NodeInterface
{

public:
	T data;
	NodeInterface* right;
	NodeInterface* left;
	size_t height;



	~NodeInterface() {}
	NodeInterface(T value)
	{
		this->data = value;
		this->left = NULL;
		this->right = NULL;
		this->height = 0;
	}

	//Returns the data stored in this node
	T getData() { return data; }

	/*
	Returns the left child of this node or null if empty left child.
	*/
	NodeInterface<T> * getLeftChild() const
	{
		return left;
	}

	/*
	* Returns the right child of this node or null if empty right child.
	*/
	NodeInterface<T> * getRightChild() const
	{
		return right;
	}


	/*
	* Returns the height of this node. The height is the number of nodes
	* along the longest path from this node to a leaf.  While a conventional
	* interface only gives information on the functionality of a class and does
	* not comment on how a class should be implemented, this function has been
	* provided to point you in the right direction for your solution.  For an
	* example on height, see page 448 of the text book.
	*
	* @return the height of this tree with this node as the local root.
	*/
	unsigned int getHeight() const
	{
		return height;
	}




	//Recursively updates height for the respective node
	T updateHeight()
	{
		if (right == NULL && left == NULL) {
			height = 1;
		}
		else if (right == NULL) {
			height = left->updateHeight() + 1;
		}
		else if (left == NULL) {
			height = right->updateHeight() + 1;
		}
		else {
			height = max(left->updateHeight(), right->updateHeight()) + 1;
		}
		return height;

	}

	int getBalance()
	{
		
		int L = (left == NULL) ? -1 : left->height;
		int R = (right == NULL) ? -1 : right->height;

		return R-L;
	}


};
#endif