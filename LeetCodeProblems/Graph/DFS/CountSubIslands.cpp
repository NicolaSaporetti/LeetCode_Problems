#include <vector>
using namespace std;

class Solution {
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        row_sz = grid1.size();
        col_sz = grid1[0].size();
        count=0;
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid2[i][j]==1)
                {
                    isSubIsland = true;
                    compMaxAreaIsland(i,j,grid2,grid1);
                    if(isSubIsland) count++;
                }
            }
        }
        return count;
    }
private:
    void compMaxAreaIsland(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& comparatorGrid) {
        if(row<row_sz && row>=0 && col<col_sz && col>=0 && grid[row][col]==1)
        {
            grid[row][col]=0;
            if(comparatorGrid[row][col]==0) isSubIsland = false;
            compMaxAreaIsland(row+1,col,grid,comparatorGrid);
            compMaxAreaIsland(row-1,col,grid,comparatorGrid);
            compMaxAreaIsland(row,col+1,grid,comparatorGrid);
            compMaxAreaIsland(row,col-1,grid,comparatorGrid);
        }
    }

    int row_sz;
    int col_sz;
    bool isSubIsland;
    int count;
};