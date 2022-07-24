#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    TreeNode* newRoot;
    
    void traverse(TreeNode* root, TreeNode* newRoot)
    {
        newRoot->val = root->val;
        if(root->left!=nullptr)
        {
            newRoot->right = new TreeNode(0);
            traverse(root->left, newRoot->right);
        }
        if(root->right!=nullptr)
        {
            newRoot->left = new TreeNode(0);
            traverse(root->right, newRoot->left);
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        newRoot = new TreeNode(0);
        traverse(root, newRoot);
        return newRoot;
    }
};