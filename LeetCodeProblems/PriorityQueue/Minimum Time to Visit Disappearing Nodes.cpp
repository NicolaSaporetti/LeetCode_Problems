#include <priority_queue>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> r(n,-1);
        vector<vector<pair<int,int>>> v(n);
        vector<int> vis(n);
        for(auto e : edges)
        {
            v[e[0]].push_back({e[1],e[2]});
            v[e[1]].push_back({e[0],e[2]});
        }
        pq.push({0,0});
        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            int node = el[1];
            int t = el[0];
            if(vis[node]) continue;
            vis[node] = true;
            if(t<disappear[node]) r[node]=t;
            else continue;
            for(auto e : v[node])
            {
                if(!vis[e.first])
                {
                    pq.push({t+e.second,e.first});
                }
            }
        }
        return r;
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
};