#include <vector>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        res = INT_MAX;
        dp.assign(n,vector<int>(pow(2,n),INT_MAX));
        for(int i=0;i<n;i++) traverse(i,1<<i, 0, graph);
        return res;
    }
private:
    void traverse(int cur, int mask, int move, vector<vector<int>>& graph)
    {
        if(dp[cur][mask]<=move) return;
        if(mask == pow(2,n)-1)
        {
            res = min(res,move);
            return;
        }
        dp[cur][mask]=move;
        for(auto e : graph[cur])
        {
            traverse(e,mask|(1<<e),move+1,graph);
        }
    }

    vector<vector<int>> dp;
    int n;
    int res;
};