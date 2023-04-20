#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;
        int res = 0;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            long long adj = -1;
            for(int i=0;i<n;i++)
            {
                auto el = q.front();
                q.pop();
                if(el->left!=nullptr)
                {
                    if(adj==-1) adj = (long long)el->val*2;
                    el->left->val = (long long)el->val*2-adj;
                    q.push(el->left);
                }
                if(el->right!=nullptr)
                {
                    if(adj==-1) adj = (long long)el->val*2+1;
                    el->right->val = (long long)el->val*2+1-adj;
                    q.push(el->right);
                }
                if(i==n-1) res = max(res,el->val+1);
            }
        }
        return res;
    }
};