#include <vector>
#include "DisjoinSetUnion.cpp"

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjoinSetUnion ds(n);
        for(int i=0;i<edges.size();i++)
        {
            ds.connect(edges[i][0],edges[i][1]);
        }
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[ds.find_set(i)]++;
        }
        long long res = 0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            res = res+ (long long)(it->second)*(long long)(n-it->second);
        }
        return res/2;   
    }
};