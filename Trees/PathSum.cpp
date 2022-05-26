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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        matchingSumFound = false;
        if(root!=nullptr)
        {
            traverse(root, targetSum);
        }
        return matchingSumFound;
	}
};

int main()
{
    Solution sol;
    return 0;
}