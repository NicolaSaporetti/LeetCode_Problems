#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    vector<vector<int>> solutions;
    vector<int> currentValues;
    
	void traverse(TreeNode* node, int leftSum)
	{
        if(node!=nullptr)
        {
            currentValues.push_back(node->val);
            if(node->left==nullptr && node->right==nullptr)
            {
                if(leftSum==node->val) solutions.push_back(currentValues);
            }
            else
            {
                traverse(node->left,leftSum-node->val);
                traverse(node->right,leftSum-node->val);
            }
            currentValues.pop_back();
        }
	}
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root!=nullptr)
        {
            traverse(root, targetSum);
        }
        return solutions;
	}
};