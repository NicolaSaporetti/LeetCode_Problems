#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* a = new TreeNode(val);
            a->left = root;
            root = a;
        }
        else traverse(root,val,depth-1);
        return root;
    }
private:
    void traverse(TreeNode* root, int val, int depth)
    {
        if(root == nullptr) return;
        if(depth==1)
        {
            root->left = new TreeNode(val,root->left,nullptr);
            root->right = new TreeNode(val,nullptr,root->right);
        }
        else 
        {
            traverse(root->left,val,depth-1);
            traverse(root->right, val, depth-1);
        }
    }
};