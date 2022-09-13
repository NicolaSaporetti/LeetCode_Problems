#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root==nullptr) return "";
        else if(root->left==nullptr && root->right==nullptr) return to_string(root->val);
        else if(root->right == nullptr) return to_string(root->val)+'('+tree2str(root->left)+')';
        return to_string(root->val)+'('+tree2str(root->left)+')'+'('+tree2str(root->right)+')';
    }
};