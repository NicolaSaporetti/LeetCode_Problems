#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        traverse(root);
        return r;
    }
private:
    int traverse(TreeNode* root)
    {
        if(root==nullptr) return 0;
        int vl = traverse(root->left);
        int vr = traverse(root->right);
        r+=abs((1-root->val)+vl+vr);
        return (1-root->val)+vl+vr;
    }

    int r;
};