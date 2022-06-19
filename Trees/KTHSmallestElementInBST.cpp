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