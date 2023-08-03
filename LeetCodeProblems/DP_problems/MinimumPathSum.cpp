#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        for(int i=1;i<rz;i++) grid[i][0]+=grid[i-1][0];
        for(int i=1;i<cz;i++) grid[0][i]+=grid[0][i-1];
        for(int i=1;i<rz;i++)
            for(int j=1;j<cz;j++)
                grid[i][j]+=min(grid[i][j-1],grid[i-1][j]);
        return grid[rz-1][cz-1];
    }
};