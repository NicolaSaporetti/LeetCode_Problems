#include <vector>
using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n,vector<int>(n,0));
        vector<int> out(n);
        int res = INT_MAX;
        for(auto& e : edges)
        {
            graph[e[0]-1][e[1]-1] = true;
            graph[e[1]-1][e[0]-1] = true;
            out[e[0]-1]++;
            out[e[1]-1]++;
        }
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(graph[i][j] && graph[i][k] && graph[j][k]) res = min(res, out[i]+out[j]+out[k]-6);
                }
            }
        }
        return (res==INT_MAX)? -1 : res;
    }
};