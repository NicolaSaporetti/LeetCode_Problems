#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool isRootToPrune = pruneZeroNode(root);
        if(isRootToPrune) root = nullptr;
        return root;
    }
private:
    bool pruneZeroNode(TreeNode* node)
    {
        if(node==nullptr) return 1;
        else
        {
            bool leftToPrune = pruneZeroNode(node->left);
            bool rightToPrune = pruneZeroNode(node->right);
            if(leftToPrune) node->left = nullptr;
            if(rightToPrune) node->right = nullptr;
            return leftToPrune & rightToPrune & node->val==0;
        }
    }
};