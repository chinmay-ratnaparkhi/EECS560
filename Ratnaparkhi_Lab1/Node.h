#ifndef _NODE_
#define _NODE_
class Node
{
	private :
		int item;
		Node* nextNode;
	
	public :
	
		//Constructors
		Node();
		Node(int anItem);
		
		//Methods
		int getItem();
		Node* getNext();
		void setNext(Node* nextNodePtr);
		void setItem(int anItem);
};
#endif