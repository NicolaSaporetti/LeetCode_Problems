#include <vector>
using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int res = INT_MAX;
        int rz = grid.size();
        int cz = grid[0].size();
        vector<vector<int>> result(rz,vector<int>(cz,INT_MAX));
        copy(grid[0].begin(),grid[0].end(),result[0].begin());
        for(int i=1;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                for(int k=0;k<cz;k++)
                {
                    result[i][j] = min(result[i][j],result[i-1][k]+moveCost[grid[i-1][k]][j]);
                }
                result[i][j]+=grid[i][j];
            }
        }
        for(int i=0;i<cz;i++)
        {
            res = min(res,result[rz-1][i]);
        }
        return res;
    }
};