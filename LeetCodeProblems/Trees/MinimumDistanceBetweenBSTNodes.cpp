#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        diff = INT_MAX;
        getMinDifference(root,INT_MIN/10,INT_MAX/10);
        return diff;
    }
private:
    void getMinDifference(TreeNode* node, int minV, int maxV)
    {
        if(node!=nullptr)
        {
            diff = min(diff,min(node->val-minV,maxV-node->val));
            getMinDifference(node->left,minV, node->val);
            getMinDifference(node->right,node->val, maxV);
        }
    }

    int diff;
};