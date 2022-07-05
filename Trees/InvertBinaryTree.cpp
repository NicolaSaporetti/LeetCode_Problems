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