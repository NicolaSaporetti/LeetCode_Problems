#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size()+1;
        vector<int> r(n);
        v.resize(n);
        for(auto e : edges)
        {
            v[e[0]].push_back({e[1],e[2]});
            v[e[1]].push_back({e[0],e[2]});
        }
        for(int i=0;i<n;i++)
        {
            vector<int> descendent;
            int sum = 0;
            int t = 0;
            for(auto e : v[i])
            {
                descendent.push_back(traverse(e.first,i,e.second,signalSpeed));
                sum+=descendent.back();
            }
            for(auto e : descendent) t+=(sum-e)*e;
            r[i]=t/2;
        }
        return r;
    }
private:
    int traverse(int node, int parent, int cost, int k)
    {
        int res = (cost%k==0);
        for(auto e : v[node])
            if(e.first!=parent) res+=traverse(e.first,node,cost+e.second,k);
        return res;
    }
    
    vector<vector<pair<int,int>>> v;
};