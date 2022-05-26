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

int main()
{
    Solution sol;
    return 0;
}