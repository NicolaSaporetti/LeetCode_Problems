#include <vector>
#include <map>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        n = passingFees.size();
        cost.assign(n,INT_MAX);
        cost[0]=passingFees[0];
        pq.push({0, 0,cost[0]});
        graph.resize(n);
        for(auto& edge : edges)
        {
            if(graph[edge[0]].find(edge[1])!=graph[edge[0]].end())
            {
                graph[edge[0]][edge[1]]=min(graph[edge[0]][edge[1]],edge[2]);
                graph[edge[1]][edge[0]]=min(graph[edge[1]][edge[0]],edge[2]);
            }
            else
            {
                graph[edge[0]][edge[1]]=edge[2];
                graph[edge[1]][edge[0]]=edge[2];
            }
        }
        computeShortestPath(maxTime, passingFees);
        return (cost[n-1]==INT_MAX)? -1 : cost[n-1];
    }
    
private:
    void computeShortestPath(int maxTime, vector<int>& passingFees)
    {
        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            
            int time_el = el[0];
            int node = el[1];
            int cost_el = el[2];
            if(cost_el>cost[node]) continue;
            cost[node] = cost_el;
            
            for (auto& [key,val] : graph[node])
            { 
                int newFee = cost_el+passingFees[key];
                int newTime = time_el+val;
                if(newTime<=maxTime && newFee<cost[key])
                {
                    pq.push({newTime, key,newFee});
                }
            }
        }
    }
    
    int n;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> cost;
    vector<map<int,int>> graph;
};