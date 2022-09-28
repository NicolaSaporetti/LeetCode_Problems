#include "TreeNode.cpp"
using namespace std;

class Solution {
private: 
    bool traverse(TreeNode* node)
    {
        if(node->val ==0) return false;
        else if(node->val == 1) return true;
        else
        {
            bool left = false;
            bool right = false;
            if(node->left!=nullptr)
            {
                left = traverse(node->left);
            }
            if(node->right!=nullptr)
            {
                right = traverse(node->right);
            }
            if(node->val ==2) return left|right;
            else return left&right;
        }
        
    }
public:
    bool evaluateTree(TreeNode* root) {
        return traverse(root);
    }
};