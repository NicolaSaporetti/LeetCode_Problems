#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        tot = 0;
        traverse(root);
        return tot;
    }
private:
    pair<int,int> traverse(TreeNode* node)
    {
        pair<int,int> res = {0,0};
        if(node!=nullptr)
        {
            auto l = traverse(node->left);
            auto r = traverse(node->right);
            res.first=l.first+r.first+1;
            res.second=l.second+r.second+node->val;
            if(res.second/res.first==node->val) tot++;
        }
        return res;
    }
    
    int tot;
};