#include <iostream>
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
    
    void traverse(TreeNode* node, int val)
    {
        if(node->val>val)
        {
            if(node->left!=nullptr) traverse(node->left, val);
            else node->left = new TreeNode(val);
        }
        else
        {
            if(node->right!=nullptr) traverse(node->right, val);
            else node->right = new TreeNode(val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        else traverse(root, val);
        return root;
    }
};