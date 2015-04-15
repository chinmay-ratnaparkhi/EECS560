#ifndef _lQ
#define _lQ

#include "leftistNode.h"

class leftistQ
{
	private:
		leftistNode** arr = new leftistNode*[20];
		int size = 20;
		int count = 0;
	public:
		leftistQ();
		~leftistQ();
		void push(leftistNode* n);
		leftistNode* pop();
		leftistNode* peek();
		bool is_empty();
};

#endif