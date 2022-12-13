#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        traverse(root);
        return sum;
    }
private:
    void traverse(TreeNode* node)
    {
        if(node->left!=nullptr)
        {
            if(node->left->left ==nullptr && node->left->right ==nullptr) sum+=node->left->val;
            else traverse(node->left);
        }
        if(node->right!=nullptr) traverse(node->right);
    }

    int sum;
};