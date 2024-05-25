#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->left!=nullptr) root->left = removeLeafNodes(root->left,target);
        if(root->right!=nullptr) root->right = removeLeafNodes(root->right,target);
        if(root->right==nullptr && root->left==nullptr && root->val == target) return nullptr;
        else return root;
    }
};