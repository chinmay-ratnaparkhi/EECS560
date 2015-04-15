#include "leftistHeap.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
	leftistHeap* heap = new leftistHeap("data.txt");
	
	cout << "..........................................................\n" << "Please choose one of the following commands:\n1- insert\n2- deletemin\n3- preorder\n4- inorder\n5- levelorder\n6- exit\n";
	int input;
	cin >> input;
	
	while(input != 6)
	{
		if(input == 1)
		{
			cout << "Which number would you like to insert?\n";
			cin >> input;
			heap->insert(input);
		}
		else if(input == 2)
		{
			heap->deletemin();
		}
		else if(input == 3)
		{
			heap->preorder();
		}
		else if(input == 4)
		{
			heap->inorder();
		}
		else if(input == 5)
		{
			heap->levelorder();
		}
		cout << "..........................................................\nPlease choose one of the following commands:\n1- insert\n2- deletemin\n3- preorder\n4- inorder\n5- levelorder\n6- exit\n";
		cin >> input;
	}
	return 0;
}