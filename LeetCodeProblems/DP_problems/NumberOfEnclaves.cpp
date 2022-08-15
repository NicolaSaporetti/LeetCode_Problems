#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int row_sz;
    int col_sz;
    bool islandIsEnclosed;
    int count;
    int islandSize;

    void compMaxAreaIsland(int row, int col, vector<vector<int>>& grid) {
        if(row<row_sz && row>=0 && col<col_sz && col>=0 && grid[row][col]==1)
        {
            grid[row][col]=0;
            if(row==0 || row == row_sz-1 || col==0 || col==col_sz-1) islandIsEnclosed = false;
            islandSize++;
            compMaxAreaIsland(row+1,col,grid);
            compMaxAreaIsland(row-1,col,grid);
            compMaxAreaIsland(row,col+1,grid);
            compMaxAreaIsland(row,col-1,grid);
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        count=0;
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]==1)
                {
                    islandSize = 0;
                    islandIsEnclosed = true;
                    compMaxAreaIsland(i,j,grid);
                    if(islandIsEnclosed) count+=islandSize;
                }
            }
        }
        return count;
    }
};