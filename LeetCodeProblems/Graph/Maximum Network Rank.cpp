#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> g(n);
        int res = 0;
        for(auto e : roads)
        {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int tot = g[i].size()+g[j].size();
                if(g[j].find(i)!=g[j].end()) tot--;
                res = max(tot,res);
            }
        return res;
            
    }
};