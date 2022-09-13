#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool res = traverse(root);
        if(!res) root = nullptr;
        return root;
    }

private:
    bool traverse(TreeNode* root)
    {
        if(root!=nullptr)
        {
            bool left = traverse(root->left);
            if(!left) root->left = nullptr;
            bool right = traverse(root->right);
            if(!right) root->right = nullptr;
            if(!left && !right && root->val == 0) return false;
            else return true;
        }
        else
        {
            return false;
        }
    }
};