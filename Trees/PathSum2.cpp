#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

int main()
{
    Solution sol;
    return 0;
}