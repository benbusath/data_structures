#ifndef BST_H
#define BST_H
#include <string>
#include <sstream>
#include <ostream>
#include "BSTInterface.h"
using std::string;
using std::endl;

template<typename T>
class BST : public BSTInterface<T>
{
private:
	struct Node
	{

		T data;
		Node* right;
		Node* left;
		~Node() {}
		Node(T value)
		{
			this->data = value;
			this->left = NULL;
			this->right = NULL;
		}
	};

	Node* root;

public:
	BST() { this->root = NULL; }
	~BST() { clearTree(); }

	/** Adds a node to the BST using the inputed data */
	bool addNode(const T& data)
	{
		if (root == NULL)
		{
			Node* node = new Node(data);
			root = node;
		}
		else if (insert(root, data))
			return true;
		else
			return false;
	}

	/** The recursive companion function to addNode */
	bool insert(Node*& node, const T& data)
	{
		if (node == NULL)
		{
			node = new Node(data);
			return true;
		}
		if (data == node->data)
			return false;

		if (data < node->data)
			return insert(node->left, data);

		if (data > node->data)
			return insert(node->right, data);
	}

	/** Returns true if inputed data is found in BST */
	bool find(T value)
	{
		return recursiveFind(root, value);
	}

	/** Recursive companion function to the find function */
	bool recursiveFind(Node*& node, T value)
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

	/** Removes node with inputed data value */
	bool removeNode(const T& data)
	{
		return recursiveRemove(root, data);
	}

	/** Recursive companion function to the removeNode function */
	bool recursiveRemove(Node*& node, const T& data)
	{
		if (node == NULL)
			return false;

		if (data < node->data)
			return recursiveRemove(node->left, data);

		if (data > node->data)
			return recursiveRemove(node->right, data);

		if (data == node->data)
		{
			if (node->left == NULL&&node->right == NULL)
			{
				Node* temp = node;
				node = NULL;
				delete temp;
				return true;
			}

			if (node->left == NULL || node->right == NULL)
			{
				if (node->left == NULL)
				{
					Node* temp = node;
					node = node->right;
					delete temp;
					return true;
				}
				if (node->right == NULL)
				{
					Node* temp = node;
					node = node->left;
					delete temp;
					return true;
				}
			}

			node->data = maxValue(node->left);
			recursiveRemove(node->left, node->data);
		}

	}

	/** Finds max value in sub tree for an inputted Node */
	T maxValue(Node*  node)
	{
		if (node == NULL)
			return -1;
		T data = node->data;
		Node* left = node->left;

		if (left != NULL)
		{
			T leftValue = maxValue(left);
			if (leftValue > data)
				data = leftValue;
		}

		Node* right = node->right;
		if (right != NULL)
		{
			T rightValue = maxValue(right);
			if (rightValue > data)
			{
				data = rightValue;
			}
		}
		return data;
	}

	/** Clears the entire BST and removes all nodes */
	bool clearTree() {

		if (root == NULL)
			return false;

		while (root != NULL) {
			recursiveRemove(root, root->data);
		}
		return true;

		//root = NULL;

	}

	/** Output nodes at a given level */
	bool outLevel(Node* root, int level, std::stringstream& outSS) const
	{
		if (root == NULL) return false;
		if (level == 0)
		{
			outSS << " " << root->data;
			if ((root->left != NULL) || (root->right != NULL)) return true;
			return false;
		}
		if ((level == 1) && !root->left && root->right) outSS << " _";
		bool left = outLevel(root->left, level - 1, outSS);
		bool right = outLevel(root->right, level - 1, outSS);
		if ((level == 1) && root->left && !root->right) outSS << " _";
		return left || right;
	} // end outLevel()

	/** Outputs BST in post order */
	string toString() const
	{
		std::stringstream outSS;
		if (root == NULL) outSS << " Empty";
		else
		{
			int level = -1;
			do
			{
				outSS << endl << "  " << ++level << ":";
			} while (outLevel(root, level, outSS));
		}
		return outSS.str();

	}

	/** Inserts toString in output stream **/
	friend std::ostream& operator<<(std::ostream& os, const BST<T>& bst)
	{
		os << bst.toString();
		return os;
	}
};
#endif