#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<set<int>> g(n);
        vector<long long> c(n,0);
        for(int i=0;i<n;i++) c[i]=values[i];
        int r = 0;
        for(auto& ed : edges)
        {
            g[ed[0]].insert(ed[1]);
            g[ed[1]].insert(ed[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(g[i].size()<=1) q.push(i);
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            if(g[el].size()==0) return r+1;
            if(c[el]%k==0)
            {
                r++;
                c[el]=0;
            }
            for(auto& e : g[el])
            {
                g[e].erase(el);
                c[e]+=c[el];
                if(g[e].size()==1) q.push(e);
            }
        }
        return -1;
    }
};