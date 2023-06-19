#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        result = INT_MAX;
        computeDif(root,-1000001,1000001);
        return result;
    }
private:
    void computeDif(TreeNode* node, int minV, int maxV)
    {
        result = min(result, min(abs(node->val-minV),abs(node->val-maxV)));
        if(node->left!=nullptr) computeDif(node->left,minV,min(node->val,maxV));
        if(node->right!=nullptr) computeDif(node->right,max(node->val,minV),maxV);
    }

    int result;
};