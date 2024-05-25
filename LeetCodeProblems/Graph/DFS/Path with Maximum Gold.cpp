#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        rz = grid.size();
        cz = grid[0].size();
        dx = {1,0,-1,0};
        dy = {0,1,0,-1};
        g.assign(rz,vector<bool>(cz,false));
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) if(grid[i][j]>0) compute(i,j,grid[i][j],grid);
        return r;
    }
private:
    void compute(int i, int j, int p, vector<vector<int>>& grid)
    {
        r = max(r, p);
        if(g[i][j]) return;
        g[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && nx<rz && ny>=0 && ny<cz && grid[nx][ny]>0 && !g[nx][ny]) compute(nx,ny,p+grid[nx][ny],grid);
        }
        g[i][j]=false;
    }

    vector<vector<bool>> g;
    int rz;
    int cz;
    int r = 0;
    vector<int> dx;
    vector<int> dy;
};