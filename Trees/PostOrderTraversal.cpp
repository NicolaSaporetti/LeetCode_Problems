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
private:
    vector<int> sol;
    void traverse(TreeNode* node)
    {
        if(node!=nullptr)
        {
            traverse(node->left);
            traverse(node->right);
            sol.push_back(node->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        traverse(root);
        return sol;
    }
};