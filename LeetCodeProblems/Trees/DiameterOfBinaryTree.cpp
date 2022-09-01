#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        result = 0;
        traverse(root);
        return result;
    }
private:
    int traverse(TreeNode* root)
    {
        if(root == nullptr) return 0;
        else 
        {
            int left = traverse(root->left);
            int right = traverse(root->right);
            result = max(left+right,result);
            return 1+max(left,right);
        }
    }

    int result;
};