#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        graph.resize(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vis.assign(n,false);
        pq.push({1,start});
        while(!pq.empty())
        {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node==end) return prob;
            if(vis[node]) continue;
            vis[node]=true;
            for(int i=0;i<graph[node].size();i++)
            {
                int newNode = graph[node][i].first;
                double newProb = graph[node][i].second*prob;
                pq.push({newProb,newNode});
            }
        }
        return 0;
    }
    
    priority_queue<pair<double,int>> pq;
    vector<vector<pair<int,double>>> graph;
    vector<bool> vis;
};