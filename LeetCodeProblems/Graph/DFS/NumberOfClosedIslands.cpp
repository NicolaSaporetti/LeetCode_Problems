#include <vector>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        int result=0;
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]==0)
                {
                    islandIsEnclosed = true;
                    compMaxAreaIsland(i,j,grid);
                    if(islandIsEnclosed) result++;
                }
            }
        }
        return result;
    }

private:
    void compMaxAreaIsland(int row, int col, vector<vector<int>>& grid) {
        if(row<row_sz && row>=0 && col<col_sz && col>=0 && grid[row][col]==0)
        {
            grid[row][col]=1;
            if(row==0 || row == row_sz-1 || col==0 || col==col_sz-1) islandIsEnclosed = false;
            compMaxAreaIsland(row+1,col,grid);
            compMaxAreaIsland(row-1,col,grid);
            compMaxAreaIsland(row,col+1,grid);
            compMaxAreaIsland(row,col-1,grid);
        }
    }

    int row_sz;
    int col_sz;
    bool islandIsEnclosed;
};