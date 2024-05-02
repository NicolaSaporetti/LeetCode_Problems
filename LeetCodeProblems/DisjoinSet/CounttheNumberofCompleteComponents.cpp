#include <vector>
#include <map>
#include "DisjoinSetUnion.cpp"
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> g(n);
        for(auto e : edges)
        {
            g[e[0]]++;
            g[e[1]]++;
        }
        DisjoinSetUnion ds(n);
        for(auto e : edges) ds.connect(e[0],e[1]);
        map<int,vector<int>> v = ds.get_sets();
        int r = 0;
        for(auto [k,e] : v)
        {
            int c = 0;
            for(auto el : e) if(g[el]==e.size()-1) c++;
            if(c==e.size()) r++;
        }
        return r;
    }
};