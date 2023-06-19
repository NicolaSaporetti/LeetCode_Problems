#include "TreeNode.cpp"
#include <queue>
using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        int minV = INT_MIN;
        int lev = 1;
        while(!q.empty())
        {
            int n = q.size();
            int sum = 0;
            for(int i=0;i<n;i++)
            {
                auto el = q.front();
                q.pop();
                sum+=el->val;
                if(el->left!=nullptr) q.push(el->left);
                if(el->right!=nullptr) q.push(el->right);
            }
            if(sum>minV)
            {
                minV = sum;
                res = lev;
            }
            lev++;
        }
        return res;
    }
};