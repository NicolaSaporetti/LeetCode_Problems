#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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