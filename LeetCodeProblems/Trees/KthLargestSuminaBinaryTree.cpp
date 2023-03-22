#include "TreeNode.cpp"
#include <vector>
using namespace std;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            long long tot = 0;
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                tot+=(long long)node->val;
                if(node->right!=nullptr) q.push(node->right);
                if(node->left!=nullptr) q.push(node->left);
            }
            sums.push_back(tot);
        }
        sort(sums.begin(),sums.end());
        return (k>sums.size())? -1 : sums[sums.size()-k];
    }
};