#include <vector>
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxArea = 0;
        rz = grid.size();
        cz = grid[0].size();
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                area = 0;
                if(grid[i][j]>0)
                {
                    addFishes(i,j,grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    private:

    void addFishes(int row, int col, vector<vector<int>>& grid) {
        area+=grid[row][col];
        grid[row][col]=0;
        if(row+1<rz && grid[row+1][col]>0) addFishes(row+1,col,grid);
        if(row>0 && grid[row-1][col]>0) addFishes(row-1,col,grid);
        if(col+1<cz && grid[row][col+1]>0) addFishes(row,col+1,grid);
        if(col>0 && grid[row][col-1]>0) addFishes(row,col-1,grid);
    }

    int rz;
    int cz;
    int area;
};