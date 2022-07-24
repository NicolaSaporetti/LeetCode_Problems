#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<int> result;
    void traverse(TreeNode* node)
    {
        result.push_back(node->val);
        if(node->left!=nullptr)
            traverse(node->left);
        if(node->right!=nullptr)
            traverse(node->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root!=nullptr)
            traverse(root);
        return result;
    }
};