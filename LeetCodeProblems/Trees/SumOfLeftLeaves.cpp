#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    int sum;
    
    void traverse(TreeNode* node)
    {
        if(node->left!=nullptr) traverseLeft(node->left);
        if(node->right!=nullptr) traverse(node->right);
    }
    void traverseLeft(TreeNode* node)
    {
        if(node->left==nullptr && node->right ==nullptr) sum+=node->val;
        else 
        {
            if(node->left!=nullptr) traverseLeft(node->left);
            if(node->right!=nullptr) traverse(node->right);
        }
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        if(root!=nullptr) traverse(root);
        return sum;
    }
};