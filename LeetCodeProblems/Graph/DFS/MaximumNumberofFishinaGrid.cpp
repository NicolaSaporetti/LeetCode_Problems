#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        row_pos.assign({1,-1,0,0});
        col_pos.assign({0,0,1,-1});
		return computeMaxFishInPond(grid);
    }
    
private:
    int computeMaxFishInPond(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<row_sz;i++)
            for(int j=0;j<col_sz;j++)
                if(grid[i][j]>0) res=max(res,computeFishInPond(grid,i,j));
        return res;
    }
    
    int computeFishInPond(vector<vector<int>>& grid, int row, int col)
    {
        queue<pair<int,int>> pos;
        pos.push({row,col});
        int tot=grid[row][col];
        grid[row][col]=0;
        while(!pos.empty())
        {
            pair<int,int> p = pos.front();
            pos.pop();
            for(int i=0;i<4;i++)
            {
                int temp_row = p.first+row_pos[i];
                int temp_col = p.second+col_pos[i];
                if(temp_row>=0 && temp_row<row_sz && temp_col>=0 && temp_col<col_sz && grid[temp_row][temp_col]>0)
                {
                    tot+=grid[temp_row][temp_col];
                    grid[temp_row][temp_col]=0;
                    pos.push({temp_row,temp_col});
                }
            }
        }
        return tot;
    }

    int row_sz;
    int col_sz;
    vector<int> row_pos;
    vector<int> col_pos;
};