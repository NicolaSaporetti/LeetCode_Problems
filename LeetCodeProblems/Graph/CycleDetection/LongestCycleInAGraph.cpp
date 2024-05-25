#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(auto e : edges)
        {
            v[e[0]].insert(e[1]);
            v[e[1]].insert(e[0]);
        }
        int r = INT_MAX;
        for(int i=0;i<n;i++) r = min(r,bfs(i,n));
        return (r==INT_MAX)? -1 : r;
    }
private:
    int bfs(int node,int n)
    {
        int r = INT_MAX;
        vector<int> c(n,-1);
        vector<int> p(n,-1);
        int cost = 1;
        queue<int> q;
        c[node]=0;
        q.push(node);
        while(!q.empty() && r==INT_MAX)
        {
            int num = q.size();
            for(int j=0;j<num;j++)
            {
                int el = q.front();
                q.pop();
                for(auto e : v[el])
                {
                    if(c[e]==-1)
                    {
                        q.push(e);
                        c[e]=cost;
                        p[e]=el;
                    }
                    else if(p[el]!=e) r = min(r,c[e]+c[el]+1);
                }
            }
            cost++;
        }
        return r;
    }
    vector<set<int>> v;
};