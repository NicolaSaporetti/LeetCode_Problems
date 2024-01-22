#include "TreeNode.cpp"
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        compute(root);
        queue<int> q;
        q.push(start);
        vis.insert(start);
        int r = -1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                int e = q.front();
                q.pop();
                for(auto el : adj[e])
                {
                    if(vis.find(el)==vis.end())
                    {
                        vis.insert(el);
                        q.push(el);
                    }
                }
            }
            r++;
        }
        return r;
    }
private:
    void compute(TreeNode* root)
    {
        if(root->left!=nullptr)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            compute(root->left);
        }
        if(root->right!=nullptr)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            compute(root->right);
        }
    }
    unordered_map<int,vector<int>> adj;
    unordered_set<int> vis;
};