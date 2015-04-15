#ifndef _SNODE_
#define _SNODE_

class skewNode
{
	private:
		skewNode* lChild;
		skewNode* rChild;
		int data = -1;
		bool empty = true;

	public:
		skewNode();
		~skewNode();
		skewNode(int x);
		bool is_empty();
		int get_data();
		void set_data(int x);
		void swap();
		skewNode* get_lChild();
		skewNode* get_rChild();
		skewNode* set_lChild(skewNode* left);
		skewNode* set_rChild(skewNode* right);
};

#endif