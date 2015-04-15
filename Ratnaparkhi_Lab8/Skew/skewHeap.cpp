#include "skewHeap.h"
#include "skewNode.h"
#include <string>

using namespace std;


skewHeap::skewHeap() 
{
	root = new skewNode();
}

skewHeap::skewHeap(string file) 
{
	root = new skewNode();
	ifstream infile;
	
	infile.open ("data.txt");
    
    string line;
    while(getline(infile, line))
    {
        stringstream  lineStream(line);
        int value;
        while(lineStream >> value)
        {
        	insert(value);
        }
    }
    infile.close();
}

skewHeap::~skewHeap()
{
	delete root;
}

void skewHeap::insert(int withValue)
{
	if (root == NULL) {
		skewNode* n_node = new skewNode(withValue);
		root = n_node;
		return;
	}
	if (root->is_empty()) 
		root->set_data(withValue);
	else 
	{
		skewNode* n_node = new skewNode(withValue);
		insert(n_node);
	}
}

void skewHeap::insert(skewNode* t)
{
	if (root->is_empty()) 
	{
		root = t;
	}
	else 
	{
		root = insert_helper(root, t);	
	}
}

skewNode* skewHeap::insert_helper(skewNode* a, skewNode* b)
{
	if (a == NULL) 
	{
		return b;
	}
	else if (b == NULL)
	{
		return a;
	}
	else 
	{
		if (a->get_data() > b->get_data()) 
		{
			return insert_helper(b, a);
		}
		else 
		{
			if (a->get_rChild() == NULL)
			{
				a->set_rChild(b);
			} 
			else 
			{
				a->set_rChild(insert_helper(a->get_rChild(), b));
			}
		}
	}
	a->swap();
	return a;
}

void skewHeap::deletemin()
{
	if (root == NULL)
	{
		return;
	}
	root = insert_helper(root->get_rChild(), root->get_lChild());
}

void skewHeap::preorder()
{
	preorder_helper(root);
}

void skewHeap::preorder_helper(skewNode* t) 
{
	if (t != NULL)
	{
		cout << t->get_data() << " ";
		preorder_helper(t->get_lChild());
		preorder_helper(t->get_rChild());
	}
}

void skewHeap::inorder()
{
	inorder_helper(root);
}

void skewHeap::inorder_helper(skewNode* t) 
{
	if (t != NULL) 
	{
		preorder_helper(t->get_lChild());
		cout << t->get_data() << " ";
		preorder_helper(t->get_rChild());
	}	
}

void skewHeap::levelorder()
{
	if (root == NULL)
	{
		return;
	}
	
	skewQ* que = new skewQ();
	
	que->push(root);
	while(!que->is_empty()) 
	{
		cout << que->peek()->get_data() << " ";
	
		if (que->peek()->get_lChild() != NULL)
		{
			que->push(que->peek()->get_lChild());
		}
		
		if (que->peek()->get_rChild() != NULL)
		{
			que->push(que->peek()->get_rChild());
		}
		que->pop();
	}
}