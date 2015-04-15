#include "skewNode.h"
#include <algorithm>

using namespace std;

skewNode::skewNode()
{
	rChild = NULL;
	lChild = NULL;
}

skewNode::~skewNode()
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

skewNode::skewNode(int withValue)
{
	rChild = NULL;
	lChild = NULL;
	data = withValue;
}

bool skewNode::is_empty()
{
	return data == -1;
}

skewNode* skewNode::set_lChild(skewNode* left)
{
	lChild = left;
}

skewNode* skewNode::set_rChild(skewNode* right)
{
	rChild = right;
}

skewNode* skewNode::get_rChild()
{
	return rChild;
}

skewNode* skewNode::get_lChild()
{
	return lChild;
}

int skewNode::get_data()
{
	return data;
}

void skewNode::set_data(int withValue)
{
	data = withValue;
}

void skewNode::swap()
{
	skewNode* swapper = lChild;
	lChild = rChild;
	rChild = swapper;
}

