#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        res = 0;
        traverseLeft(root->left,0);
        traverseRight(root->right,0);
        return res;
    }
private:
    void traverseLeft(TreeNode* node, int ZizZag)
    {
        if(node!=nullptr)
        {
            res = max(res,ZizZag+1);
            traverseLeft(node->left,0);
            traverseRight(node->right,ZizZag+1);
        }
    }
    void traverseRight(TreeNode* node, int ZizZag)
    {
        if(node!=nullptr)
        {
            res = max(res,ZizZag+1);
            traverseLeft(node->left,ZizZag+1);
            traverseRight(node->right,0);
        }
    }

    int res;
};