#include <iostream>
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
    int traverse(TreeNode* current)
    {
        int nodes = 0;
        if(current!=nullptr)
        {
            nodes++;
            nodes+=traverse(current->left);
            nodes+=traverse(current->right);
        }
        return nodes;
    }
public:
    int countNodes(TreeNode* root) {
        return traverse(root);
    }
};