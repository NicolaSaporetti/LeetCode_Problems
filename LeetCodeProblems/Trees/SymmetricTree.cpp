#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        treeIsSimmetric = true;
        traverse(root,root);
        return treeIsSimmetric;
    }
    
private:
    void traverse(TreeNode* nodeLeft, TreeNode* nodeRight)
    {
        if(!treeIsSimmetric || (nodeLeft != nullptr && nodeRight == nullptr) || (nodeLeft==nullptr && nodeRight!=nullptr) || (nodeLeft !=nullptr && nodeRight!=nullptr && nodeLeft->val!=nodeRight->val)) treeIsSimmetric = false;
        else if(nodeLeft != nullptr && nodeRight != nullptr)
        {
            traverse(nodeLeft->left,nodeRight->right);
            traverse(nodeLeft->right,nodeRight->left);
        }
    }
    bool treeIsSimmetric;
};