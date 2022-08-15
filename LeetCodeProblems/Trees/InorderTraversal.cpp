#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    vector<int> result;
    void traverse(TreeNode* node)
    {
        if(node->left!=nullptr)
            traverse(node->left);
        result.push_back(node->val);
        if(node->right!=nullptr)
            traverse(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root!=nullptr)
            traverse(root);
        return result;
    }
};