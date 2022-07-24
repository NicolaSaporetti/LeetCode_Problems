#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
    bool treeIsSimmetric;
    void traverse(TreeNode* rootLeft, TreeNode* rootRight)
    {
        if(!treeIsSimmetric || (rootLeft == nullptr && rootRight == nullptr)) return;
        else if((rootLeft != nullptr && rootRight == nullptr) || (rootLeft == nullptr && rootRight != nullptr))
        {
            treeIsSimmetric = false;
            return;
        }
        else if(rootLeft->val!=rootRight->val)
        {
            treeIsSimmetric = false;
            return;
        }
        else
        {
            traverse(rootLeft->left,rootRight->right);
            traverse(rootLeft->right,rootRight->left);
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        treeIsSimmetric = true;
        if(root==nullptr) return treeIsSimmetric;
        traverse(root->left, root->right);
        return treeIsSimmetric;
    }
};