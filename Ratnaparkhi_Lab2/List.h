#include<iostream>
#include "Node.cpp"

#ifndef _LIST_
#define _LIST_
class List
{
	private :
		
		Node* head;
	
	public :
		
		// Constructor
		List();
		
		// Inserts an item if it doesn't exist in the list
		void insert(int anItem);
		
		// Recursive insert helper
		void insertHelper(Node* starter, int anItem);
		
		// Returns true if the list is empty
		bool isEmpty(); 
		
		// Deletes an item from the list if it exists
		void erase(int anItem);
		
		// Prints the list in a well formatted manner
		void print();
		
		// Returns pointer to the node containing required item
		Node* find(int anItem, Node* searcher);	
		
		Node* getHead();
		
};
#endif