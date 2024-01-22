#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> v(n-1,0);
        g.resize(n);
        for(auto& e : edges)
        {
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
        }
        sz = n;
        for(int i=1;i<(1<<n);i++)
        {
            if(isConnected(i,edges))
            {
                cout<<i<<endl;
                v[checkDist(edges,i)-1]++;
            }
        }
        return v;
    }
private:
    bool isConnected(int mask, vector<vector<int>>& edges)
    {
        set<int> s;
        for(int i=0;i<sz;i++) if(mask&(1<<i)) s.insert(i);
        if(s.size()<2) return false;
        queue<int> q;
        q.push(*s.begin());
        s.erase(*s.begin());
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            for(auto e : g[el])
                if(s.find(e)!=s.end())
                {
                    q.push(e);
                    s.erase(e);
                }
        }
        return s.empty();
    }
    
    int checkDist(vector<vector<int>>& edges, int mask)
    {
        int maxD = 0;
        set<int> s;
        for(int i=0;i<sz;i++) if(mask&(1<<i)) s.insert(i);
        if(s.size()==2) return 1;
        vector<int> adj(sz,0);
        for(auto e : s)
            for(auto ade : g[e]) adj[ade]++;
        vector<int> dist(sz,0);
        queue<int> q;
        for(auto e : s) if(adj[e]==1) q.push(e);
        while(!q.empty())
        {
            int el = q.front();
            s.erase(el);
            q.pop();
            adj[el]=0;
            for(auto& e : g[el])
            {
                if(s.find(e)==s.end()) continue;
                adj[e]--;
                if(adj[e]==1) q.push(e);
                maxD = max(maxD, dist[el]+dist[e]+1);
                dist[e]=max(dist[e],1+dist[el]);
            }
        }
        return maxD;
    }
    
    int sz;
    vector<vector<int>> g;
};