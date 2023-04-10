#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int tot = 0;
        if(root!=nullptr)
        {
            if(root->val>=low && root->val<=high) tot+=root->val;
            if(root->val<high) tot+=rangeSumBST(root->right,low,high);
            if(root->val>low) tot+=rangeSumBST(root->left,low,high);
        }
        return tot;
    }
};