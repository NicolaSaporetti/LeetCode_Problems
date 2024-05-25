#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        g.resize(n);
        for(auto e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        c.resize(n);
        for(auto e : trips) computeTrip(-1,e[0],e[1]);
        dp.assign(n,vector<int>(2,-1));
        return dfs(0,false,-1,price);
    }
private:
    void computeTrip(int prev, int node, int tgt)
    {
        trip.push_back(node);
        if(node==tgt) for(auto e : trip) c[e]++;
        else
        {
            for(auto e : g[node])
            {
                if(e!=prev) computeTrip(node,e,tgt);
            }
        }
        trip.pop_back();
    }
    int dfs(int node, bool sel, int prev, vector<int>& price)
    {
        if(dp[node][sel]!=-1) return dp[node][sel];
        else
        {
            int v1 = c[node]*price[node];
            for(auto e : g[node]) if(e!=prev) v1+=dfs(e,false,node,price);
            int v2 = 1e9;
            if(!sel)
            {
                v2 = c[node]*price[node]/2;
                for(auto e : g[node]) if(e!=prev) v2+=dfs(e,true,node,price);
            }
            return dp[node][sel]=min(v1,v2);
        }
    }

    vector<vector<int>> g;
    vector<int> c;
    vector<int> trip;
    vector<vector<int>> dp;
};