#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        result = true;
        traverse(root,((long long) INT_MIN)-1,((long long)INT_MAX)+1);
        return result;
    }
private:
    void traverse(TreeNode* node, long long left, long long right)
    {
        if(node!=nullptr && result)
        {
            if(static_cast<long long>(node->val)<=left || 
               static_cast<long long>(node->val)>=right) result = false;
            traverse(node->left,left,node->val);
            traverse(node->right,node->val,right);
        }
    }
    
    bool result;
};