#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        newTree = nullptr;
        if(root==nullptr) return newTree;
        else{
            explore(root, root);
        }
        return head;
    }
private:
    void add_element(TreeNode* current)
    {
        if(newTree==nullptr)
        {
            newTree = new TreeNode(current->val);
            head = newTree;
        }
        else{
            newTree->right = new TreeNode(current->val);
            newTree = newTree->right;
        }
    }
    void explore(TreeNode* current, TreeNode* root)
    {
        if(current->left==nullptr && current->right==nullptr)
        {
            add_element(current);
        }
        else
        {
            if(current->left!=nullptr)
            {
                explore(current->left, current);
            }
            add_element(current);
            if(current->right!=nullptr)
            {
                explore(current->right, current);
            }
        }
    }

    TreeNode* newTree;
    TreeNode* head;
};