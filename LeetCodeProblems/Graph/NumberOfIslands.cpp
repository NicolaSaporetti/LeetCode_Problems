#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
		return computeNumIslands(grid);
    }
    
private:
    
    int computeNumIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]=='1')
                {
                    removeIsland(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void removeIsland(vector<vector<char>>& grid, int row, int col)
    {
        array<int,4> row_pos = {1,-1,0,0};
        array<int,4> col_pos = {0,0,1,-1};
        queue<pair<int,int>> pos;
        pos.push({row,col});
        grid[row][col]='0';
        while(!pos.empty())
        {
            pair<int,int> p = pos.front();
            pos.pop();
            for(int i=0;i<4;i++)
            {
                int temp_row = p.first+row_pos[i];
                int temp_col = p.second+col_pos[i];
                if(temp_row>=0 && temp_row<row_sz && temp_col>=0 && temp_col<col_sz && grid[temp_row][temp_col]=='1')
                {
                    grid[temp_row][temp_col]='0';
                    pos.push({temp_row,temp_col});
                }
            }
        }
    }

    int row_sz;
    int col_sz;
};