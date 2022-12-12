#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxVal = INT_MIN;
        computeVal(root);
        return maxVal;
    }
    
private:
    int computeVal(TreeNode* root)
    {
        int val = 0;
        if(root!=nullptr)
        {
            val = root->val;
            int left_val = computeVal(root->left);
            int right_val = computeVal(root->right);
            if(left_val>=0 && right_val>=0)
            {
                maxVal = max(maxVal,val+left_val+right_val);
                val += max(left_val,right_val);
            }
            else if(left_val>=0)
            {
                maxVal = max(maxVal,val+left_val);
                val += left_val;
            }
            else if(right_val>=0)
            {
                maxVal = max(maxVal,val+right_val);
                val += right_val;
            }
            else maxVal = max(maxVal,val);
        }
        return val;
    }

    int maxVal;
};