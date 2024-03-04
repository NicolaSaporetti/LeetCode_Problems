
#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            int e0 = edges[i][0];
            int e1 = edges[i][1];
            graph[e0].push_back({e1,succProb[i]});
            graph[e1].push_back({e0,succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<bool> vis(n,false);
        pq.push({1.0,start_node});
        while(!pq.empty())
        {            
            double cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=true;
            if (node == end_node) return cost;
            for (int i = 0; i<graph[node].size();i++)
            {
                int ne = graph[node][i].first;
                if(!vis[ne]) pq.push({cost*graph[node][i].second,ne});
            }
        }
        return 0;
    }
    
    vector<vector<pair<int,int>>> graph;
};