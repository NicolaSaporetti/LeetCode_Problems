#include <vector>
using namespace std;

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        vector<vector<int>> grid2 = grid;
        int tot = 0;
        for(int i=rz-2;i>=0;i--)
        {
            for(int j=1;j<=cz-2;j++)
            {
                if(grid[i][j]!=0)
                {
                    tot+=computePir(i,j,grid);
                }
            }
        }
        for(int i=1;i<rz;i++)
        {
            for(int j=1;j<=cz-2;j++)
            {
                if(grid2[i][j]!=0)
                {
                    tot+=computeInvPir(i,j,grid2);
                }
            }
        }
        return tot;
    }
private:
    int computePir(int r, int c, vector<vector<int>>& grid)
    {
        grid[r][c]= 1+min(min(grid[r+1][c-1],grid[r+1][c]),grid[r+1][c+1]);
        return grid[r][c]-1;
    }
    int computeInvPir(int r, int c, vector<vector<int>>& grid)
    {
        grid[r][c]= 1+min(min(grid[r-1][c-1],grid[r-1][c]),grid[r-1][c+1]);
        return grid[r][c]-1;
    }
};