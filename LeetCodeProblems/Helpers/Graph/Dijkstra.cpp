#include <vector>
#include <priority_queue>
using namespace std;

vector<int> dijkstra(int src, int n, vector<vector<int>>& edges)
{
    vector<int> dist(n,-1);
    vector<vector<vector<int>>> g(n);
    for(int i=0;i<edges.size();i++)
    {
        g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        g[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto el = pq.top();
        pq.pop();
        int cost = el[0];
        int node = el[1];
        if(dist[node]!=-1) continue;
        dist[node]=cost;
        for (auto e : g[node]) {
            int newNode = e[0];
            int newCost = e[1]+cost;
            if(dist[newNode]!=-1) continue;
            pq.push({newCost,newNode});
        }
    }
    return dist;
}