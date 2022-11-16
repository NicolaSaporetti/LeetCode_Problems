#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        minLevel = INT_MAX;
        if(root == nullptr) minLevel = 0;
        else traverse(root, 1);
        return minLevel;
	}
    
private:
	void traverse(TreeNode* p, int level)
	{
        if(p->right==nullptr && p->left==nullptr) minLevel = min(minLevel, level);
        else
        {
            if(p->left!=nullptr) traverse(p->left,level+1);
            if(p->right!=nullptr) traverse(p->right,level+1);
        }
	}
    
	int minLevel;
};