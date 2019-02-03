//YOU MAY NOT MODIFY THIS DOCUMENT
#ifndef AVL_H_
#define AVL_H_

#include <iostream>
#include "NodeInterface.h"

using namespace std;

template<class T>
class AVL
{
private:
	NodeInterface<T>* root;
public:
	AVL() { root = NULL; }





	/*
	* Attempts to add the given T to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the T is already in tree)
	*/
	bool add(T data)
	{
		if (root == NULL)
		{
			NodeInterface<T>* node = new NodeInterface<T>(data);
			root = node;
			return true;
		}
		else if(find(data))
		{
			return false;
		}
		else
		{
			root = insert(root, data);
			return true;
		}
	}

	/** The recursive companion function to addNode */
	NodeInterface<T>* insert(NodeInterface<T>*& node, const T& data)
	{
		if (node == NULL)
		{
			node = new NodeInterface<T>(data);
			return node;
		}

		if (data < node->data)
		{
			node->left=insert(node->left, data);
			return checkBalance(node);	
		}

		if (data > node->data)
		{
			node->right=insert(node->right, data);
			return checkBalance(node);
		}
	}

	void rotateLeft(NodeInterface<T>*& node)
	{
		NodeInterface<T>* pivot=node->right;
		

		node->right = pivot->left;
		pivot->left = node;

		pivot->updateHeight();
		node->updateHeight();
	}


	void rotateRight(NodeInterface<T>*& node)
	{
		NodeInterface<T>* pivot = node->left;
		NodeInterface<T>* T2 = pivot->right;

		pivot->right = node;
		node->left = T2;

		pivot->updateHeight();
		node->updateHeight();
	}
	/*
	* Attempts to remove the given T from the AVL tree
	* Rebalances the tree if data is successfully removed
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the T is not in the tree)
	*/
	

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear() { return; }

	NodeInterface<T> * getRootNode() { return root; }

	/*
	* Attempts to add the given T to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the T is already in tree)
	*/

	
	
	
	


	/** Returns true if inputed data is found in BST */
	bool find(T value)
	{
		return recursiveFind(root, value);
	}

	/** Recursive companion function to the find function */
	bool recursiveFind(NodeInterface<T>*& node, T value)
	{
		if (node == NULL)
			return false;

		if (node->data == value)
			return true;

		if (value < node->data)
			return recursiveFind(node->left, value);

		if (value > node->data)
			return recursiveFind(node->right, value);

		return false;
	}


	NodeInterface<T>* checkBalance(NodeInterface<T>*& node )
	{
		if (node == NULL) { return NULL; }
		node->updateHeight();

		if (node->getBalance() > 1)
		{
			NodeInterface<T>* right = node->right;
			if (right->getBalance() >= 0)
			{
				rotateLeft(node);
				return right;
			}
			else
			{
				rotateRight(right);
				rotateLeft(node);
				return right->left;
			}
		}

		else if (node->getBalance() < -1)
		{
			NodeInterface<T>* left = node->left;
			if (left->getBalance() <= 0)
			{
				rotateRight(node);
				return left;
			}
			else
			{
				rotateLeft(left);
				rotateRight(node);
				return left->right;
			}
		}
		else
			return node;
	}

	
	

	NodeInterface<T>* IoP(NodeInterface<T>* curr, NodeInterface<T>* node)
	{
		if (node->left->right == NULL)
		{
			NodeInterface<T>* curr = node->left;
			T swapData = node->data;
			node->data = curr->data;
			curr->data = swapData;

			NodeInterface<T>* saved = node->left;
			delete curr;

			return checkBalance(saved);
		}
		else
		{
			curr->right = IoP(curr->right, node);
			return checkBalance(curr);
		}
	}

	NodeInterface<T>* recRemove(NodeInterface<T>* node, T data)
	{
		if (data == node->data)
		{
			if (node->left == NULL)
			{
				NodeInterface<T>* temp = node->right;
				delete node;
				return checkBalance(temp);
			}
			else
			{
				node->left = IoP(node->left, node);
				return checkBalance(node);
			}
		}

		if (data < node->data)
		{
			node->left = recRemove(node->left, data);
			return checkBalance(node);
		}
		if (data > node->data)
		{
			node->right = recRemove(node->right, data);
			return checkBalance(node);
		}
	}

	bool remove(T data)
	{
		if (find(data))
		{
			root = recRemove(root, data);
			return true;
		}
		else
			return false;
	}
};

#endif