#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        matchingSumFound = false;
        if(root!=nullptr) traverse(root, targetSum);
        return matchingSumFound;
	}
    
private:
	void traverse(TreeNode* node, int leftSum)
	{
        if(!matchingSumFound)
        {
            if(node->left==nullptr && node->right==nullptr)
            {
                if(leftSum==node->val) matchingSumFound = true;
            }
            else
            {
                if(node->left!=nullptr) traverse(node->left,leftSum-node->val);
                if(node->right!=nullptr) traverse(node->right,leftSum-node->val);
            }
        }
	}
    
	bool matchingSumFound;
};