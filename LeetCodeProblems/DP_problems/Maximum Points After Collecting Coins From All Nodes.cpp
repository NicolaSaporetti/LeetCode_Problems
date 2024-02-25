#include <vector>
using namespace std;

class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        sz = coins.size();
        gtl = buildDirectGraphToLeafs(edges,sz);
        v.assign(sz,vector<int>(15,-1));
        return helper(0,0,coins,k);
    }
private:
    int helper(int node, int div, vector<int>& coins, int k)
    {
        if(v[node][div]!=-1) return v[node][div];
        else
        {
            int v1 = coins[node]/pow(2,div)-k;
            int v2 = 0;
            for(int i=0;i<gtl[node].size();i++) v1+=helper(gtl[node][i],div,coins,k);
            if(div<14)
            {
                v2 = coins[node]/pow(2,div+1);
                for(int i=0;i<gtl[node].size();i++) v2+=helper(gtl[node][i],div+1,coins,k);
            }
            return v[node][div]=max(v1,v2);
        }
    }

    int sz;
    vector<vector<int>> v;
    vector<vector<int>> gtl;
};