#include "TreeNode.cpp"
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n);
        queue<int> q;
        for(auto e : edges)
        {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        int num = n;
        for(int i=0;i<n;i++)
            if(g[i].size()<=1)
            {
                q.push(i);
                num--;
            }
        while(num>0)
        {
            int k = q.size();
            for(int i=0;i<k;i++)
            {
                int el = q.front();
                q.pop();
                for(auto e : g[el])
                {
                    g[e].erase(el);
                    if(g[e].size()==1)
                    {
                        q.push(e);
                        num--;
                    }
                }
            }
        }
        vector<int> r;
        while(!q.empty())
        {
            r.push_back(q.front());
            q.pop();
        }
        return r;
    }
};