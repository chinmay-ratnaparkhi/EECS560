#include "leftistQ.h"

leftistQ::leftistQ(){}
leftistQ::~leftistQ(){}
bool leftistQ::is_empty()
{
	if(count != 0)
	{
		return false;
	}
	return true;
}

leftistNode* leftistQ::peek()
{
	return arr[0];
}

void leftistQ::push(leftistNode* t)
{
	if(count == size-1)
	{
		leftistNode** temp = new leftistNode*[size*2];
		for(int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		arr = temp;
		size = size*2;
	}
	arr[count] = t;
	count++;
}

leftistNode* leftistQ::pop()
{
	leftistNode* temp = arr[0];
	for(int i = 0; i < size-1; i++)
	{
		arr[i] = arr[i+1];
	}
	count--;
	return temp;
}