#ifndef _skewHeap_H
#define _skewHeap_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "skewNode.h"
#include "skewQ.h"

using namespace std;

class skewHeap 
{

	private:
		skewNode* root;
		skewNode* insert_helper(skewNode* a, skewNode* b);
		void preorder_helper(skewNode* t);
		void inorder_helper(skewNode* t);

	public:
		skewHeap();
		~skewHeap();
		skewHeap(string file);
		void inorder();
		void preorder();
		void levelorder();
		void insert(int x);
		void insert(skewNode* t);
		void deletemin();

};

#endif