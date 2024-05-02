#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        g.resize(n);
        vector<vector<vector<int>>> adj(n);
        sz = n;
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back({edges[i][1],edges[i][2],i});
            g[edges[i][1]].push_back({edges[i][0],edges[i][2],i});
        }
        bool r =computeShortestPathFromDest(source,destination,target,computeShortestPathFromSource(source,destination), edges);
        vector<vector<int>> empty;
        return (r)? edges : empty;
    }
private:
    vector<int> computeShortestPathFromSource(int src, int dst)
    {
        vector<int> dd(sz,-1);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto el = pq.top();
            int cost = el[0];
            int node = el[1];
            pq.pop();
            if(dd[node]!=-1) continue;
            dd[node]=cost;
            for (auto e : g[node]) {
                int n = e[0];
                if(dd[n]!=-1) continue;
                int c = (e[1]==-1)? 1 : e[1];
                if(c==-1) pq.push({cost+1,n});
                else pq.push({cost+c,n});
            }
        }
        return dd;
    }
    bool computeShortestPathFromDest(int src, int dst, int target, vector<int> dd, vector<vector<int>>& edges)
    {
        vector<int> dm(sz,-1);
        priority_queue<vector<int>> pq;
        pq.push({target, dst});
        while (!pq.empty()) {
            auto el = pq.top();
            int cost = el[0];
            int node = el[1];
            if(cost<0) break;
            pq.pop();
            if(dm[node]!=-1) continue;
            dm[node]=cost;
            for (auto e : g[node]) {
                int n = e[0];
                int c = e[1];
                int edge = e[2];
                if(dm[n]!=-1) continue;
                if(c==-1)
                {
                    c = max(1,cost-dd[n]);
                    edges[edge][2]=c;
                }
                pq.push({cost-c,n});
            }
        }
        for(auto& e : edges) if(e[2]==-1) e[2]=1e9;
        return (dm[src]==0);
    }
    vector<vector<vector<int>>> g;
    int sz;    
};