#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        rz = grid.size();
        cz = grid[0].size();
        int r = 0;
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++)
                if(grid[i][j]=='1')
                {
                    r++;
                    computeIsland(i,j,grid);
                }
        return r;
    }
private:
    void computeIsland(int i, int j, vector<vector<char>>& grid)
    {
        grid[i][j]='0';
        for(int k=0;k<4;k++)
        {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && nx<rz && ny>=0 && ny<cz && grid[nx][ny]=='1') computeIsland(nx,ny,grid);
        }
    }

    int rz;
    int cz;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
};