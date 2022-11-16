#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
	    areTreesTheSame = true;
		traverse(p,q);
		return areTreesTheSame;
    }
private:
	void traverse(TreeNode* p, TreeNode* q)
	{
		if(areTreesTheSame)
		{
            if((p!=nullptr && q==nullptr) || (p==nullptr && q!=nullptr) || (p!=nullptr && q!=nullptr && p->val!=q->val)) areTreesTheSame = false;
            else if(p!=nullptr && q!=nullptr)
            {
                traverse(p->left,q->left);
                traverse(p->right,q->right);
            }
		}
	}
    
	bool areTreesTheSame;
};