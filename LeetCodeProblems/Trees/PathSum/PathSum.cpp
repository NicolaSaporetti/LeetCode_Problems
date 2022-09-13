#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        matchingSumFound = false;
        if(root!=nullptr)
        {
            traverse(root, targetSum);
        }
        return matchingSumFound;
	}
private:
	bool matchingSumFound;
	void traverse(TreeNode* node, int leftSum)
	{
        if(node!=nullptr && !matchingSumFound)
        {
            if(node->left==nullptr && node->right==nullptr)
            {
                if(leftSum==node->val) matchingSumFound = true;
            }
            else
            {
                traverse(node->left,leftSum-node->val);
                traverse(node->right,leftSum-node->val);
            }
        }
	}
};