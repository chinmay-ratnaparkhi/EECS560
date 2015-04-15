#include "leftistNode.h"
#include <algorithm>

using namespace std;

leftistNode::leftistNode()
{
	rChild = NULL;
	lChild = NULL;
}

leftistNode::~leftistNode()
{
	if (rChild != NULL)
	{
		delete rChild;
	}
	if (lChild != NULL)
	{
		delete lChild;
	}
}

leftistNode::leftistNode(int withValue)
{
	rChild = NULL;
	lChild = NULL;
	data = withValue;
	get_rank();
}

int leftistNode::rank()
{
	return myRank;	
}

void leftistNode::get_rank()
{
	if (lChild == NULL || rChild == NULL)
	{
		myRank = 1;
	} 
	else 
	{
		myRank = min(lChild->rank(), rChild->rank()) + 1;
	}
}

bool leftistNode::is_empty()
{
	return data == -1;
}

leftistNode* leftistNode::set_lChild(leftistNode* left)
{
	lChild = left;
	get_rank();
}

leftistNode* leftistNode::set_rChild(leftistNode* right)
{
	rChild = right;
	get_rank();
}

leftistNode* leftistNode::get_rChild()
{
	return rChild;
}

leftistNode* leftistNode::get_lChild()
{
	return lChild;
}

int leftistNode::get_data()
{
	return data;
}

void leftistNode::set_data(int withValue)
{
	data = withValue;
}

void leftistNode::swap()
{
	leftistNode* swapper = lChild;
	lChild = rChild;
	rChild = swapper;
}

