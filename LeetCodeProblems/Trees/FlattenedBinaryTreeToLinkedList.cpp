#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root!=nullptr)
        {
            head = new TreeNode(root->val);
            current = head;
            traverse(root->left);
            traverse(root->right);
            &root->left = nullptr;
            root->right = head->right;
        }
    }
private:
    void traverse(TreeNode* node)
    {
        if(node!=nullptr)
        {
            current->right = new TreeNode(node->val);
            current = current->right;
            traverse(node->left);
            traverse(node->right);
        }
        
    }
    TreeNode* head;
    TreeNode* current;
};