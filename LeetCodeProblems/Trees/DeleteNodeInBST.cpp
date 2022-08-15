#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    int key;
    bool keyFound;
    
    void deleteKey(TreeNode* node, TreeNode* root)
    {
        if(node->right==nullptr && node->left==nullptr)
        {
            if(root == nullptr) node->val = INT_MAX;
            else if(root->left!=nullptr && root->left->val ==key) root->left = nullptr;
            else root->right = nullptr;
        }
        else if(node->right!=nullptr)
        {
            TreeNode* rootR = node;
            TreeNode* nodeR = node->right;
            while(nodeR->left!=nullptr)
            {
                rootR = nodeR;
                nodeR= nodeR->left;
            }
            node->val = nodeR->val;
            if(rootR==node)
            {
                if(nodeR->right!=nullptr)
                {
                    rootR->right = nodeR->right;
                }
                else
                {
                    rootR->right = nullptr;
                }
            }
            else
            {
                if(nodeR->right!=nullptr)
                {
                    rootR->left = nodeR->right;
                }
                else
                {
                    rootR->left = nullptr;
                }
            }
        }
        else
        {
            TreeNode* rootL = node;
            TreeNode* nodeL = node->left;
            while(nodeL->right!=nullptr)
            {
                rootL = nodeL;
                nodeL= nodeL->right;
            }
            node->val = nodeL->val;
            if(rootL==node)
            {
                if(nodeL->left!=nullptr)
                {
                    rootL->left = nodeL->left;
                }
                else
                {
                    rootL->left = nullptr;
                }
            }
            else
            {
                if(nodeL->left!=nullptr)
                {
                    rootL->right = nodeL->left;
                }
                else
                {
                    rootL->right = nullptr;
                }
            }
        }
    }
    
    void traverse(TreeNode* node, TreeNode* root)
    {
        if(keyFound) return;
        if(node->val == key)
        {
            keyFound = true;
            deleteKey(node,root);
            return;
        }
        if(node->left!=nullptr)
            traverse(node->left,node);
        if(node->right!=nullptr)
            traverse(node->right,node);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        this->key = key;
        keyFound = false;
        if(root!=nullptr)
        {
            traverse(root,nullptr);
            if(root->val == INT_MAX) root = nullptr;
        }
        return root;
    }
};