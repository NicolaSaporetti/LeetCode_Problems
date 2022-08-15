#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
    TreeNode* sol;
    bool solutionFound;
    
    void search(TreeNode* node, int val)
    {
        if(!solutionFound && node!=nullptr)
        {
            if(node->val == val) sol = node;
            search(node->left, val);
            search(node->right,val);
        }
    }
    
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        solutionFound = false;
        sol = nullptr;
        search(root, val);
        return sol;
    }
};