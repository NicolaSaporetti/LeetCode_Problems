#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int cost = 0;
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto& edge : times) graph[edge[0]].push_back({edge[1],edge[2]});
        vector<int> visited(n+1,false);
        pq.push({0,k});
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            int nodeNum = node.second;
            if(visited[nodeNum]) continue;
            visited[nodeNum] = true;
            cost = node.first;
            
            for (int i = 0; i<graph[nodeNum].size(); i++)
            {
                auto newNode = graph[nodeNum][i];
                pq.push({newNode.second+cost,newNode.first});
            }
        }
        for(int i=1;i<=n;i++) if(!visited[i]) return -1;
        return cost;
    }
private:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
};