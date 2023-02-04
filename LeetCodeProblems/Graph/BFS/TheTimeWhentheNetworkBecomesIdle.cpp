#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> graph(n);
        for(auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        queue<int> q;
        vis.assign(n,false);
        cost.assign(n,0);
        q.push(0);
        vis[0]=true;
        int Cost = 0;
        while(!q.empty())
        {
            Cost++;
            int num = q.size();
            for(int i=0;i<num;i++)
            {
                int el = q.front();
                q.pop();
                for(auto& newN : graph[el])
                {
                    if(!vis[newN])
                    {
                        vis[newN]=true;
                        cost[newN]=Cost;
                        q.push(newN);
                    }
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++) res = max(res,computeTime(cost[i],patience[i]));
        return res;
    }
private:
    int computeTime(int cost, int patience)
    {
        if(cost*2<=patience) return cost*2+1;
        else
        {
            int rest = (cost*2)%patience;
            if(rest ==0) rest = patience;
            return cost*4-rest+1;
        }
    }
    
    vector<bool> vis;
    vector<int> cost;
};