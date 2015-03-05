#include<iostream>
#include "Node.h"

//Constructors
Node::Node()
{
	nextNode= NULL;
}

Node::Node(int anItem)
{
	nextNode= NULL;
	item= anItem;
}

//Methods
int Node::getItem()
{
	return item;
}

Node* Node::getNext()
{
	return nextNode;
}

void Node::setNext(Node* nextNodePtr)
{
	nextNode= nextNodePtr;
}

void Node::setItem(int anItem)
{
	item= anItem;
}