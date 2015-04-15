#ifndef _lHeap
#define _lHeap

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "leftistNode.h"
#include "leftistQ.h"

class leftistHeap 
{

	private:
		leftistNode* root;
		int rank;
		leftistNode* insert_helper(leftistNode* a, leftistNode* b);
		void preorder_helper(leftistNode* t);
		void inorder_helper(leftistNode* t);

	public:
		leftistHeap();
		~leftistHeap();
		leftistHeap(std::string file);
		void inorder();
		void preorder();
		void levelorder();
		void insert(int x);
		void insert(leftistNode* t);
		void deletemin();

};

#endif