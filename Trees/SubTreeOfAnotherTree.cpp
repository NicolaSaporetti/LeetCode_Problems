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
public:
    bool areIdentical(TreeNode* root1, TreeNode* root2) {
        return (!root1 && !root2)
            || (
                root1
                && root2
                && root1->val == root2->val
                && areIdentical(root1->left, root2->left)
                && areIdentical(root1->right, root2->right)
            );
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return areIdentical(root, subRoot) 
            || (root->left && isSubtree(root->left, subRoot))
            || (root->right && isSubtree(root->right, subRoot));
    }
};