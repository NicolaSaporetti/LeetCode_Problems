#include <vector>
#include <queue>
#include <priority_queue>
using namespace std;

class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(auto& e : edges) graph[e[0]].push_back({e[1],e[2]});
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(graph.size(),false);
        pq.push({0,node1});
        while(!pq.empty())
        {            
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=true;
            if (node ==node2) return cost;
            for (int i = 0; i<graph[node].size();i++)
            {
                int ne = graph[node][i].first;
                if(!vis[ne])
                {
                    pq.push({cost+graph[node][i].second,ne});
                }
            }
        }
        return -1;
    }
    
    vector<vector<pair<int,int>>> graph;
};