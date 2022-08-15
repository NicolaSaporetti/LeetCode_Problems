#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
private:
    bool found;
    int value;
    void traverse(TreeNode* node, int& k)
    {
        if(node!=nullptr && !found)
        {
            traverse(node->left,k);
            k--;
            if(!k)
            {
                found = true;
                value = node->val;
            }
            traverse(node->right,k);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return value;
    }
};