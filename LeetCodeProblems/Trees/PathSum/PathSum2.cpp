#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root!=nullptr) traverse(root, targetSum);
        return solutions;
	}
    
private:
	void traverse(TreeNode* node, int leftSum)
	{
        currentValues.push_back(node->val);
        if(node->left==nullptr && node->right==nullptr)
        {
            if(leftSum==node->val) solutions.push_back(currentValues);
        }
        else
        {
            if(node->left!=nullptr) traverse(node->left,leftSum-node->val);
            if(node->right!=nullptr) traverse(node->right,leftSum-node->val);
        }
        currentValues.pop_back();
	}
    
    vector<vector<int>> solutions;
    vector<int> currentValues;
};