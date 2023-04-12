#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return computeDifference(root,root->val,root->val);
    }
private:
    int computeDifference(TreeNode* node,int minV, int maxV)
    {
        int diff = max(abs(node->val-minV),abs(node->val-maxV));
        if(node->left!=nullptr) diff = max(diff,computeDifference(node->left,min(minV,node->val),max(maxV,node->val)));
        if(node->right!=nullptr) diff = max(diff,computeDifference(node->right,min(minV,node->val),max(maxV,node->val)));
        return diff;
    }
};