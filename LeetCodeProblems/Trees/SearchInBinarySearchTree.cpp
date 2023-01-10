#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        solutionFound = false;
        sol = nullptr;
        search(root, val);
        return sol;
    }
private:  
    void search(TreeNode* node, int val)
    {
        if(!solutionFound && node!=nullptr)
        {
            if(node->val == val) sol = node;
            search(node->left, val);
            search(node->right,val);
        }
    }
    TreeNode* sol;
    bool solutionFound;
};