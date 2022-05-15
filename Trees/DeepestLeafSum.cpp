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
public:
    vector<int> result;
    int maxLevel;
    int sumDeepestLeafs;
        
    void computeMaxLevel(TreeNode* node, int level)
    {
        if(level>maxLevel) maxLevel = level;
        if(node->left!=nullptr)
            computeMaxLevel(node->left, level+1);
        if(node->right!=nullptr)
            computeMaxLevel(node->right, level+1);
    }
    
    void sumDeepestLeaves(TreeNode* node, int level)
    {
        if(level == maxLevel)
        {
            sumDeepestLeafs+=node->val;
        }
        else
        {
            if(node->left!=nullptr)
                sumDeepestLeaves(node->left, level+1);
            if(node->right!=nullptr)
                sumDeepestLeaves(node->right, level+1);
        }
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        maxLevel = 0;
        sumDeepestLeafs = 0;
        if(root!=nullptr)
        {
            computeMaxLevel(root, 0);
            sumDeepestLeaves(root, 0);
        }
        return sumDeepestLeafs;
    }
};

int main()
{
    Solution solution;
    return 0;
}