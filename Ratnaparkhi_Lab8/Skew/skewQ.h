#ifndef _skewQ_H
#define _skewQ_H

#include "skewNode.h"

class skewQ
{
	private:
		skewNode** arr = new skewNode*[20];
		int size = 20;
		int count = 0;
	public:
		skewQ();
		~skewQ();
		void push(skewNode* n);
		skewNode* pop();
		skewNode* peek();
		bool is_empty();
};

#endif