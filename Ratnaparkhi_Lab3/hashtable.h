#include <iostream>
class hashtable
{
private:

	int* container;
	bool* flag;
	int size;

public:

	hashtable(int provided_size);
	~hashtable();
	int hash(int item);
	int find(int item);
	void insert(int item);
	void remove(int item);
	void print(); 
	bool consists(int x);
	bool isFull();

};
