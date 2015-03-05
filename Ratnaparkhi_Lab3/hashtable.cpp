#include "hashtable.h"
using namespace std;

hashtable::hashtable(int provided_size)
{
	size = provided_size;
	container= new int[size];
	flag = new bool[size];
	
	int counter= 0;
	while(counter < size)
	{ 
		container[counter]=-1;
		flag[counter]=false;	
		counter++;
	}
}

hashtable::~hashtable()
{
	delete[] container;
	delete[] flag;
}

int hashtable::hash(int item)
{
	int index=-1;
	int turn=0;
	while (turn < size)
	{
		index = (item % size + turn*turn) % size;
		if (container[index] == -1) return index;
		else turn++;
	}
	
	return -1;
}


int hashtable::find(int item)
{
	int index=-1;
	int i=0;
	
	while(i < size)
	{
		index = (item % size + i*i) % size;
		if(container[index]==item) return index;
		else
		{
			if(container[index]==-1 && !flag[index]) return -1;
			i++;
		}
	}
	
	return -1;
}


void hashtable::insert(int item)
{
	if(!isFull())
	{
		if(!consists(item))	
		{
			int index = hash(item);
			if(index==-1)
			{
				cout << "No space available for : " << item <<". Hashtable is not full. \n";
			}
			else
			{
				container[index] = item;
				flag[index]=false;
				cout << "Inserted : " << item << ". " << endl;
			}
		}
		else cout << "Item Already exists. " << endl;
	}
	else
	{
		cout << "Hash table is full.\n";
		
	}
}

void hashtable::remove(int item)
{
	if(find(item)!=-1)
	{
		int index= find(item);
		container[index]=-1;
		flag[index]=true;
		cout << "Removed : " << item << ". " << endl;
	}
	else cout << "Not found. " << endl;
}



void hashtable :: print()
{
	cout << " Q: \n";
	for(int i=0; i<size; i++)
	{
		cout<< i << ": ";
		if(!flag[i]) cout << container[i] <<" flag=false" ;
		else cout << container[i] <<" flag=true";
	
		cout << endl;
	}

}

bool hashtable::consists(int x)
{
	if(find(x)==-1) return false;
	else return true;	
}

bool hashtable :: isFull()
{
	for(int i=0; i<size; i++) if(container[i]==-1) return false;
	return true;
}
