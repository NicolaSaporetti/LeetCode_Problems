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