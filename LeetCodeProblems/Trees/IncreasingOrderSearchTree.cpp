#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        current->left = nullptr;
        current->right = nullptr;
        return newroot;
    }
private:
    void traverse(TreeNode* node)
    {
        if(node!=nullptr)
        {
            traverse(node->left);
            if(newroot==nullptr)
            {
                newroot = node;
                newroot->left = nullptr;
                current = newroot;
            }
            else
            {
                current->right = node;
                current->left = nullptr;
                current = current->right;
            }
            traverse(node->right);
        }
    }

    TreeNode* newroot;
    TreeNode* current;
};