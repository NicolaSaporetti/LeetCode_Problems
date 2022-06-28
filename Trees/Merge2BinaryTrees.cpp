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
    void traverse(TreeNode* node, TreeNode* result)
    {
        result->val = node->val;
        
        if(node->right!=nullptr)
        {
            result->right = new TreeNode(0);
            traverse(node->right, result->right);
        }
        if(node->left!=nullptr)
        {
            result->left = new TreeNode(0);
            traverse(node->left, result->left);
        }
    }
    void traverseD(TreeNode* node1, TreeNode* node2, TreeNode* result)
    {
        result->val = node1->val+node2->val;
        result->right = new TreeNode(0);
        result->left = new TreeNode(0);
        
        if(node1->right!=nullptr && node2->right!=nullptr) traverseD(node1->right, node2->right, result->right);
        else if(node1->right==nullptr && node2->right!=nullptr) traverse(node2->right, result->right);
        else if(node1->right!=nullptr && node2->right==nullptr) traverse(node1->right, result->right);
        else result->right = nullptr;
        
        if(node1->left!=nullptr && node2->left!=nullptr) traverseD(node1->left, node2->left, result->left);
        else if(node1->left==nullptr && node2->left!=nullptr) traverse(node2->left, result->left);
        else if(node1->left!=nullptr && node2->left==nullptr) traverse(node1->left, result->left);
        else result->left = nullptr;
        
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* result = new TreeNode(0);
        if(root1!=nullptr && root2!=nullptr) traverseD(root1, root2, result);
        else if(root1==nullptr && root2!=nullptr) traverse(root2, result);
        else if(root1!=nullptr && root2==nullptr) traverse(root1, result);
        else result = nullptr;
        return result;
    }
};