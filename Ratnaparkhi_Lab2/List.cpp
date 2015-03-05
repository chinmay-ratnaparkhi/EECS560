#include<iostream>
#include "List.h"

using namespace std;
// Constructors
List::List()
{
	head= NULL;
}

// Methods
void List::insert(int anItem)
{ 
	Node* alreadyExists= find(anItem, head);
	if(alreadyExists != NULL)
	{
		cout << "--" << endl;
	}
	else
		{
			if(isEmpty())
			{
				head = new Node(anItem);
			}
			else
				{
					insertHelper(head, anItem);
				}
		}
}


void List::insertHelper(Node* pointer, int anItem)
{
	if(pointer->getNext() != NULL)
	{
		insertHelper(pointer->getNext(), anItem);
	}
	else{
			Node* insertPointer= new Node(anItem);
			insertPointer->setNext(NULL);
			pointer->setNext(insertPointer);
		}
}
	

/*	Returns true if the list is empty. 
*/
bool List::isEmpty(){ return (head== NULL); }


/* 	Recursively searches through the list for a given item
	if found, removes the item from the list.
*/
void List::erase(int anItem)
{

	/*  find(anItem, head) returns the pointer to the node containing the
		desired element. */
	Node* toBeErased= find(anItem, head);
	
	// The item was not found in any of the nodes.
	if(toBeErased == NULL)
	{
		cout << "Provided value was not found." << endl;
	}
	
	// The item was found in the head node and it is the ONLY node in the list.
	else if(toBeErased == head && toBeErased->getNext() == NULL)
	{
		delete toBeErased;
		toBeErased= NULL;
		head= NULL;
	}
	
	/* 	The found node is the last node of the list, i.e. there are no successive
		nodes to copy data from. */
	else if(toBeErased->getNext() == NULL)
	{
		int count=0;
		Node* prev= head;
		Node* toBeErased= head;
		while(toBeErased->getNext() != NULL)
		{
			if(count == 0)
			{
				count= count+1;

			}
			else
				{
					prev= prev->getNext();
				}		
			toBeErased= toBeErased->getNext();	
		}
			
			delete toBeErased;
			toBeErased= NULL;
			prev->setNext(NULL);
			prev= NULL;
	}
	
	/*	The node was found somewhere between the head and tail. Data from the successive
		node is copied to the found node.The process is repeated until the end of the 
		list and the last node is deleted.
	*/
	else
		{
			int count=0;
			Node* prev= toBeErased;
			while(toBeErased->getNext() != NULL)
			{
				if(count == 0)
				{
					count= count+1;
				}
				else
					{
						prev= prev->getNext();
					}
				toBeErased->setItem(toBeErased->getNext()->getItem());
				toBeErased= toBeErased->getNext();
			}
			
			delete toBeErased;
			toBeErased= NULL;
			prev->setNext(NULL);
			prev= NULL;
		}
}

/*	Finds the desired item in the list and returns pointer to the node
	that contains the value. 
*/
Node* List::find(int anItem, Node* searcher)
{
	// searcher will be NULL if the list is empty or End is reached.
	if(searcher == NULL){ return NULL; }

	// current Node contains the item, return pointer to it.
	if(searcher->getItem()== anItem){ return searcher; }

	// Recurse on the remaining list until node is found
	else
		{
			return find(anItem, searcher->getNext());
		}
}


/* Prints the items in a list in a well-formatted manner.
*/
void List::print()
{
	if(isEmpty()){ cout << " List is empty." << endl; }
	else
		{
			Node* currentPointer= head;
			while (currentPointer != NULL)
			{
				std::cout << " " << currentPointer->getItem();
				currentPointer= currentPointer->getNext();
			}
			cout << endl;
		}
}

Node* List::getHead()
{
	return head;
}