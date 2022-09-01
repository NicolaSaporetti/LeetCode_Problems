#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        goodNodeNumber = 0;
        verifyNodeIsGood(root,INT_MIN);
        return goodNodeNumber;
    }
private:
    void verifyNodeIsGood(TreeNode* node, int value)
    {
        if(node!=nullptr)
        {
            if(node->val>=value)
            {
                value = node->val;
                goodNodeNumber++;
            }
            verifyNodeIsGood(node->left,value);
            verifyNodeIsGood(node->right,value);
        }
    }
    
    int goodNodeNumber;
};