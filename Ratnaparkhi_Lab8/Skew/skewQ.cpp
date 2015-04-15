#include "skewQ.h"

skewQ::skewQ(){}
skewQ::~skewQ(){}

skewNode* skewQ::peek()
{
	return arr[0];
}

bool skewQ::is_empty()
{
	if(count != 0)
	{
		return false;
	}
	return true;
}

skewNode* skewQ::pop()
{
	skewNode* temp = arr[0];
	for(int i = 0; i < size-1; i++)
	{
		arr[i] = arr[i+1];
	}
	count--;
	return temp;
}

void skewQ::push(skewNode* t)
{
	if(count == size-1)
	{
		skewNode** temp = new skewNode*[size*2];
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