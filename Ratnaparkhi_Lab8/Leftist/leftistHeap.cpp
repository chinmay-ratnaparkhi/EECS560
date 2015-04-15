#include "leftistHeap.h"
#include "leftistNode.h"
#include <string>

using namespace std;

leftistHeap::leftistHeap()
{
	root = new leftistNode();
}

leftistHeap::~leftistHeap()
{
	delete root;
}

leftistHeap::leftistHeap(string file)
{
	root = new leftistNode();
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

void leftistHeap::insert(int x)
{
	if (root == NULL)
	{
		leftistNode* n_node = new leftistNode(x);
		root = n_node;
		return;
	}
	if (root->is_empty())
	{
		root->set_data(x);
	}
	else
	{
		leftistNode* n_node = new leftistNode(x);
		insert(n_node);
	}
}

void leftistHeap::insert(leftistNode* t)
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

leftistNode* leftistHeap::insert_helper(leftistNode* a, leftistNode* b) 
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

	if(a->get_lChild() == NULL) 
	{
		a->swap();
	} 
	else 
	{
		if (a->get_lChild()->rank() < a->get_rChild()->rank()) 
		{
			a->swap();
		}
	}
	return a;
}

void leftistHeap::deletemin() 
{
	if (root == NULL)
	{
		return;
	}
	root = insert_helper(root->get_rChild(), root->get_lChild());
}

void leftistHeap::preorder()
{
	preorder_helper(root);
}

void leftistHeap::preorder_helper(leftistNode* t) 
{
	if (t != NULL) 
	{
		cout << t->get_data() << " ";
		preorder_helper(t->get_lChild());
		preorder_helper(t->get_rChild());
	}
}

void leftistHeap::inorder() 
{
	inorder_helper(root);
}

void leftistHeap::inorder_helper(leftistNode* t) 
{
	if (t != NULL) 
	{
		preorder_helper(t->get_lChild());
		cout << t->get_data() << " ";
		preorder_helper(t->get_rChild());
	}	
}

void leftistHeap::levelorder()
{
	if (root == NULL)
	{
		return;
	}
	leftistQ* que = new leftistQ();
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