#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <string>
#include <sstream>

#include "LinkedListInterface.h"
using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
public:
	
	LinkedList(){head = NULL;}
	~LinkedList(){clear(); }
	/** Insert Node at beginning of linked list (no duplicates) */
	bool insertHead(T value)
	{
		if (find(value) == false)
		{
			if (head == NULL)
			{
				head = new Node(value);
				return true;
			}
			else
			{
				Node *ptr;
				ptr = new Node(value, head);
				head = ptr;
				return true;
			}
		}
		else if (find(value) == true)
			return false;
	}
	/** Insert Node at end of linked list (no duplicates) */
	bool insertTail(T value)
	{
		if (find(value) == false)
		{
		if (head == NULL)
		{
			head = new Node(value);
			return true;
		}
		Node* ptr = head;
		while (1)
		{
			if (find(value) == true) { return false; }
			else if (ptr->next == NULL) { break; }
			else { ptr = ptr->next; }
		}
		ptr->next = new Node(value);
		return true;
	}
		else if (find(value) == true)
			return false;
	}

	/** Insert node after matchNode (no duplicates) */
	bool insertAfter(T matchNode, T node)
	{
		if (find(node) == true) { return false; }
		if (find(matchNode) == true)
		{
			Node* ptr = head;
			Node* toAdd;
			while (1)
			{
				if (ptr->data == matchNode) { break; };
				ptr = ptr->next;
			}
			toAdd = new Node(node, ptr->next);
			ptr->next = toAdd;
			return true;
		}
		else if (find(matchNode) == false)
			return false;
	}


	/** Return Node at index (0 based) */
	 T at(int index) 
	{
		if (index < 0 || index >= size()) { throw invalid_argument("too large an index"); }
		else 
		{
			Node* ptr = head;
			for (int i = 0; i <= index; i++)
			{
				if (i = index) { return ptr->data; }
				else { ptr = ptr->next; };
			}
		}
	}

	 ///** Remove Node from linked list */
	 virtual bool remove(T value)
	 {
		 if (size() == 0) { return false; }
		 if (head->data == value)
		 {
			 Node* ptr = head;
			 if (ptr->next != NULL) { head = ptr->next; }
			 delete ptr;
			 return true;
		 }

		 else if (head->data != value)
		 {
			 Node* ptr = head;
			 while (1)
			 {
				 if (ptr->next == NULL) {return false;}
				 else if (ptr->next->data != value)
				 {
					  
					 ptr = ptr->next;
				 }
				 else if (ptr->next->data == value)
				 {
					 Node* ptr2 = ptr->next;
					 ptr->next = ptr2->next;
					 delete ptr2;
					 return true;
				 }
			 }	
		 }

		 else return false;
	 }

	 /** Remove all Nodes from linked list */
	 //Have an error that I couldn't figure out in this function, ran out of time
	 bool clear() 
	 {
		 if (size() == 0) { return false; }
		 while (head != NULL)  
			 remove(head->data);

		 return true;
	 };

	/** Returns the number of nodes in the linked list */
	int size() const
	{
		int size = 0;
		if (head == NULL) { return size; }
		Node* ptr = head;

		
		size = 1;

		while (1)
		{
			if (ptr->next == NULL) { break; }
			else if(ptr->next != NULL) { size++; }
			ptr = ptr->next;
		}
		return size;
	}

	/* Determines if inputed node is in linked list*/
	bool find(T value)
	{
		Node* ptr = head;
		while(1)
		{
			if (ptr == NULL) { return false; }
			else if (value == ptr->data) { return true; }
			else { ptr = ptr->next; }
		}
		return false;
	}
	/** Returns the linked list contents */
	string toString() const 
	{ 
		Node* ptr = head;
		ostringstream outSS;
		while (1)
		{
			const string NULL_STRING = "";
			if (ptr == NULL) { return NULL_STRING; }
			else if (ptr->next == NULL) { outSS << ptr->data; break; }
			else if (ptr->next != NULL) { outSS<<ptr->data<<" "; }
			ptr = ptr->next;
		}
		return outSS.str();
	};

	/** Inserts toString in output stream **/
	friend std::ostream& operator<< (ostream& os, const LinkedList<T>& linkedList)
	{
		os << linkedList.toString();
		return os;
	} // end operator<<
	
private:
	
	struct Node 
	{
		T data;
		Node* next;
		Node(T d) : next(NULL) { this->data = d; }
		Node(T d, Node* n) { this->data = d; this->next = n; }
	};
	Node *head, *tail;

};
#endif	// LINKED_LIST_INTERFACE_H#pragma once
