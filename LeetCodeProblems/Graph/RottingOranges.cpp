#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        setup_initial_rotten_oranges(grid);
        int time_oranges_rot = time_to_rot_oranges(grid);
        if(!are_all_oranges_rot(grid)) time_oranges_rot = -1;
        return time_oranges_rot;
    }
    
private:
    void setup_initial_rotten_oranges(vector<vector<int>>& grid)
    {
        row_sz = grid.size();
        col_sz = grid[0].size();
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]==2) rottenOranges.push({i,j});
            }
        }
    }
    
    int time_to_rot_oranges(vector<vector<int>>& grid)
    {
        array<int,4> row_pos = {1,-1,0,0};
        array<int,4> col_pos = {0,0,1,-1};
        int res = -1;
        do {
            res++;
            int current_rotten_oranges = rottenOranges.size();
            for(int i=0;i<current_rotten_oranges;i++)
            {
                auto el = rottenOranges.front();
                rottenOranges.pop();
                for(int i=0;i<4;i++)
                {
                    int nr = el.first+row_pos[i];
                    int nc = el.second+col_pos[i];
                    if(nr>=0 && nr<row_sz && nc>=0 && nc<col_sz && grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        rottenOranges.push({nr,nc});
                    }
                }
            }
        } while(!rottenOranges.empty());
        return res;
    }
    
    bool are_all_oranges_rot(vector<vector<int>>& grid)
    {
        bool oranges_are_all_rot = true;
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]==1) oranges_are_all_rot = false;
            }
        }
        return oranges_are_all_rot;
    }
    
    queue<pair<int,int>> rottenOranges;
    int row_sz;
    int col_sz;
};