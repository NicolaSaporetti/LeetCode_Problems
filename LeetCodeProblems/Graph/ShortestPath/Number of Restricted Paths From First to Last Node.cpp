#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        sz = n;
        graph.resize(sz);
        for(auto& e : edges)
        {
            graph[e[0]-1].push_back({e[1]-1,e[2]});
            graph[e[1]-1].push_back({e[0]-1,e[2]});
        }
        return restrictedPath(shortestPath(sz-1));
    }
private:
    vector<int> shortestPath(int node1) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(sz,-1);
        pq.push({0,node1});
        while(!pq.empty())
        {            
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]!=-1) continue;
            vis[node]=cost;
            for (int i = 0; i<graph[node].size();i++)
            {
                int ne = graph[node][i].first;
                if(vis[ne]==-1)
                {
                    pq.push({cost+graph[node][i].second,ne});
                }
            }
        }
        return vis;
    }
    
    int restrictedPath(vector<int> dist) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<sz;i++) pq.push({dist[i],i});
        vector<int> res(sz,0);
        res[sz-1]=1;
        int mod = 1e9+7;
        while(!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();
            for(auto& n : graph[node])
            {
                if(dist[n.first]>dist[node]) res[n.first]=(res[n.first]+res[node])%mod;
            }
        }
        return res[0];
    }
    
    vector<vector<pair<int,int>>> graph;
    int sz;
};