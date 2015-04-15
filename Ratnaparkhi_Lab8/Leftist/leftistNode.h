#ifndef _LNODE_
#define _LNODE_

class leftistNode
{
	private:
		leftistNode* lChild;
		leftistNode* rChild;
		int data = -1;
		bool empty = true;
		int myRank = 0;
		void get_rank();

	public:
		leftistNode();
		~leftistNode();
		leftistNode(int x);
		int rank();
		bool is_empty();
		int get_data();
		void set_data(int x);
		void swap();
		leftistNode* get_lChild();
		leftistNode* get_rChild();
		leftistNode* set_lChild(leftistNode* left);
		leftistNode* set_rChild(leftistNode* right);
};

#endif