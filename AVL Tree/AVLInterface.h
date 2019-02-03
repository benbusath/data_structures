//YOU MAY NOT MODIFY THIS DOCUMENT
#ifndef AVLINTERFACE_H_
#define AVLINTERFACE_H_

#include <iostream>
#include "NodeInterface.h"

using namespace std;

template<class T>
class AVLInterface {
public:
	AVLInterface() {}
	virtual ~AVLInterface() {}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	virtual NodeInterface<T> * getRootNode() const = 0;

	/*
	* Attempts to add the given T to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the T is already in tree)
	*/
	virtual bool add(T data) = 0;

	/*
	* Attempts to remove the given T from the AVL tree
	* Rebalances the tree if data is successfully removed
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the T is not in the tree)
	*/
	virtual bool remove(T data) = 0;

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	virtual void clear() = 0;
};

#endif /* AVLINTERFACE_H_ */