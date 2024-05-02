#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int v = grid[i][j];
                grid[i][j]=INT_MAX;
                for(int z=0;z<n;z++)
                {
                    if(z==j) continue;
                    grid[i][j] = min(grid[i][j],v+grid[i-1][z]);
                }
            }
        }
        return *min_element(begin(grid[n-1]),end(grid[n-1]));
    }
};