#include <priority_queue>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        sz = n;
        int mod = 1e9+7;
        graph.resize(n);
        for(auto& road : roads)
        {
            graph[road[0]].push_back({road[1],road[2]});
            graph[road[1]].push_back({road[0],road[2]});
        }
        vis.assign(n,false);
        time.resize(n);
        time[0][0]=1;
        pq.push({0,0});
        while(!pq.empty())
        {
            int el = pq.top().second;
            long long baseC = pq.top().first;
            if(el==n-1) return time[n-1].begin()->second;
            pq.pop();
            if(vis[el]) continue;
            vis[el]=true;
            for(int i=0;i<graph[el].size();i++)
            {
                int newNode = graph[el][i].first;
                long long cost = graph[el][i].second+baseC;
                time[newNode][cost]=(time[newNode][cost]+time[el].begin()->second)%mod;
                pq.push({cost,newNode});
            }
        }
        return -1;
    }
    
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    vector<vector<pair<int,long long>>> graph;
    vector<bool> vis;
    vector<map<long long,int>> time;
    int sz;
};