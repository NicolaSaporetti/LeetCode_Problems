#include <map>
#include <set>
#include <queue>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        traverse(root);
        visited.insert(target->val);
        queue<int> q;
        q.push(target->val);
        int n=0;
        while(n<k)
        {
            int num = q.size();
            for(int i=0;i<num;i++)
            {
                int el = q.front();
                q.pop();
                for(auto& e : g[el])
                {
                    if(visited.find(e)==visited.end())
                    {
                        visited.insert(e);
                        q.push(e);
                    }
                }
            }
            n++;
        }
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
private:
    void traverse(TreeNode* root)
    {
        if(root->left!=nullptr)
        {
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            traverse(root->left);
        }
        if(root->right!=nullptr)
        {
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
            traverse(root->right);
        }
    }

    map<int,vector<int>> g;
    set<int> visited;
};