#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int res = 0;
        outOfRange = 100000000;
        vector<vector<int>> g(n,vector<int>(n,outOfRange));
        for(auto& e : roads)
        {
            g[e[0]][e[1]]=min(g[e[0]][e[1]],e[2]);
            g[e[1]][e[0]]=min(g[e[1]][e[0]],e[2]);
        }
        for(int i=0;i<n;i++) g[i][i]=0;
        for(int i=0;i<(1<<n);i++)
        {
            vector<vector<int>> g1 = g;
            for(int j=0;j<n;j++)
            {
                if(!((1<<j)&i))
                {
                    for(int z=0;z<n;z++)
                    {
                        g1[j][z]= outOfRange;
                        g1[z][j]= outOfRange;
                    }
                }
            }
            if(FloydWarshall(g1,maxDistance)) res++;
        }
        return res;
    }
private:    
    bool FloydWarshall(vector<vector<int>>& g, int maxDistance)
    {
        int n = g.size();
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]); 
                }
            }
        }
        int tot = 0;
        for(int i=0;i<n;i++) if(g[i][i]==0) tot++;
        int valid = 0;
        for(auto r : g)
            for(auto c : r) if(c<=maxDistance) valid++;
        return tot*tot==valid;
    }

    int outOfRange;
};