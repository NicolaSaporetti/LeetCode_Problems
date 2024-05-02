#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        while(!q.empty())
        {
            int n = q.size();
            int s = 0;
            for(int i=0;i<n;i++)
            {
                auto e = q.front();
                q.pop();
                if(e->left) s+=e->left->val;
                if(e->right) s+=e->right->val;
                q.push(e);
            }
            for(int i=0;i<n;i++)
            {
                auto e = q.front();
                q.pop();
                int t=0;
                if(e->left) t+=e->left->val;
                if(e->right) t+=e->right->val;
                if(e->left)
                {
                    e->left->val=s-t;
                    q.push(e->left);
                }
                if(e->right)
                {
                    e->right->val=s-t;
                    q.push(e->right);
                }
            }
        }
        return root;
    }
};