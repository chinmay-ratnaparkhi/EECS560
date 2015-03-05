#include "Hashtable.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

int TABLE_SIZE;
Hashtable::Hashtable(int size)
{
	TABLE_SIZE = size;
	htable = new List[TABLE_SIZE];
	for(int i= 0; i< TABLE_SIZE; i++)
	{
		htable[i] = List();
	}
}
Hashtable::~Hashtable()
{
	delete[] htable;
}     
int Hashtable::hashFunction(int key)
{
	return key % TABLE_SIZE;
}
void Hashtable::insert(int key)
{
	int index = hashFunction(key);
	htable[index].insert(key);	
}
//Remove Element at a key
void Hashtable::remove(int key)
{
	int index= hashFunction(key);
	htable[index].erase(key);
}
bool Hashtable::find(int key)
{
	return true;
}
void Hashtable::print()
{
	for(int i= 0; i< TABLE_SIZE; i++)
	{
		cout << i << " : ";
		htable[i].print();
	}
}