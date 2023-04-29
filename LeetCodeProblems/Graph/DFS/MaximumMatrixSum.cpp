#include <vector>
#include <queue>
#include <array>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        row_pos.assign({1,-1,0,0});
        col_pos.assign({0,0,1,-1});
        isOdd = false;
		flip(grid);
        long long res = 0;
        long long min = INT_MAX;
        for(auto& row : grid)
            for(auto& c : row)
            {
                res+=(long long)c;
                if(c<min) min = c;
            }
        return (isOdd)? res-2*min : res;
    }
    
private:
    void flip(vector<vector<int>>& grid) {
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]<0)
                {
                    flipNegative(grid,i,j);
                }
            }
        }
    }
    
    void flipNegative(vector<vector<int>>& grid, int row, int col)
    {
        queue<pair<int,int>> pos;
        pos.push({row,col});
        grid[row][col]*=-1;
        int tot = 1;
        while(!pos.empty())
        {
            pair<int,int> p = pos.front();
            pos.pop();
            for(int i=0;i<4;i++)
            {
                int temp_row = p.first+row_pos[i];
                int temp_col = p.second+col_pos[i];
                if(temp_row>=0 && temp_row<row_sz && temp_col>=0 && temp_col<col_sz && grid[temp_row][temp_col]<0)
                {
                    tot++;
                    grid[temp_row][temp_col]*=-1;
                    pos.push({temp_row,temp_col});
                }
            }
        }
        if(tot%2==1) isOdd = !isOdd;
    }

    int row_sz;
    int col_sz;
    vector<int> row_pos;
    vector<int> col_pos;
    bool isOdd;
};