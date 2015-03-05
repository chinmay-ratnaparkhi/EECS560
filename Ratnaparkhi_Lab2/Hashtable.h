#ifndef _HASHTABLE_
#define _HASHTABLE_

#include "List.cpp"

class Hashtable
{
    private:
        List* htable;
        
    public:
        Hashtable(int size);
		~Hashtable();
		void insert(int key);
		void remove(int key);
		void print();
		int hashFunction(int key);
		bool find(int key);
};

#endif