#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        res = 0;
        traverse(root);
        return res;
    }
    
private:
    pair<int,int> traverse(TreeNode* node)
    {
        if(node==nullptr) return {0,0};
        else
        {
            auto v1 = traverse(node->right);
            auto v2 = traverse(node->left);
            int firstV = node->val+v1.second+v2.second;
            int secondV = v1.first+v2.first;
            res = max(firstV,secondV);
            return {max(firstV,secondV),secondV};
        }
    }

    int res;
};