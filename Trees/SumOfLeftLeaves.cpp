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