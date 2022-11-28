#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root!=nullptr) invertNode(root);
        return root;
    }
    
private:
    void invertNode(TreeNode* root)
    {
        swap(root->left,root->right);
        if(root->left!=nullptr) invertNode(root->left);
        if(root->right!=nullptr) invertNode(root->right);
    }
};