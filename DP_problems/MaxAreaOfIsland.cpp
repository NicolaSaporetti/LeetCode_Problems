#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int row_sz;
    int col_sz;
    int area;

    void compMaxAreaIsland(int row, int col, vector<vector<int>>& grid) {
        if(row<row_sz && row>=0 && col<col_sz && col>=0 && grid[row][col]==1)
        {
            grid[row][col]=0;
            area++;
            compMaxAreaIsland(row+1,col,grid);
            compMaxAreaIsland(row-1,col,grid);
            compMaxAreaIsland(row,col+1,grid);
            compMaxAreaIsland(row,col-1,grid);
        }
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        row_sz = grid.size();
        col_sz = grid[0].size();
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                area = 0;
                if(grid[i][j]==1)
                {
                    compMaxAreaIsland(i,j,grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};