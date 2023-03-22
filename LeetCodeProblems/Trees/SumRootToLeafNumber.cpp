#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        else return traverse(root,0);
    }
private:
    int traverse(TreeNode* node, int val)
    {
        int tot = 0;
        if(node->left==nullptr && node->right==nullptr) tot = val*10+node->val;
        if(node->left!=nullptr) tot+=traverse(node->left,val*10+node->val);
        if(node->right!=nullptr) tot+=traverse(node->right,val*10+node->val);
        return tot;
    }
};