#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    bool ans;
    int dfs(TreeNode*root)
    {
        if(!root || !ans)
            return 0;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(abs(l-r)>1)
            ans=false;
        
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        ans=true;
        int p =dfs(root);
        return ans;
    }
};