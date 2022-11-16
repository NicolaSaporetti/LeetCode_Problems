#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        ans=true;
        dfs(root);
        return ans;
    }

private:
    int dfs(TreeNode*root)
    {
        if(root==nullptr || !ans) return 0;
        else
        {
            int l = dfs(root->left);
            int r = dfs(root->right);
            if(abs(l-r)>1) ans=false;
            return max(l,r)+1;
        }
    }
    
    bool ans;
};