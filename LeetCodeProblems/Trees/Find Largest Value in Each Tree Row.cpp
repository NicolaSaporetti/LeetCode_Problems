#include <vector>
#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root!=nullptr) q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int r = INT_MIN;
            for(int i=0;i<n;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                r = max(r,t->val);
                if(t->left!=nullptr) q.push(t->left);
                if(t->right!=nullptr) q.push(t->right);
            }
            res.push_back(r);
        }
        return res;
    }
};