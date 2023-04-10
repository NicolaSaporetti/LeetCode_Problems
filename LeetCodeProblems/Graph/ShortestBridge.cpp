#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        int dist=0;
        rz = grid.size();
        cz = grid[0].size();
        dx = {1,-1,0,0};
        dy = {0,0,1,-1};
        bool coast_set = false;
        for(int i=0;i<rz && !coast_set;i++)
            for(int j=0;j<cz && !coast_set;j++)
                if(grid[i][j]==1)
                {
                    fill_queue(i,j,grid);
                    coast_set=true;
                }
        while(!q.empty())
        {
            dist++;
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto el = q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nx = el.first+dx[j];
                    int ny = el.second+dy[j];
                    if(nx>=0 && nx<rz && ny>=0 && ny<cz)
                    {
                        if(grid[nx][ny]==0)
                        {
                            grid[nx][ny]=-1;
                            q.push({nx,ny});
                        }
                        if(grid[nx][ny]==1) return dist-1;
                    }
                }
            }
        }
        return -1;
    }
private:
    void fill_queue(int r, int c, vector<vector<int>>& grid)
    {
        if(r>=rz || r<0 || c>=cz || c<0 || grid[r][c]!=1) return;
        q.push({r,c});
        grid[r][c]=-1;
        for(int i=0;i<4;i++)
        {
            fill_queue(r+dx[i],c+dy[i],grid);
        }
    }

    int rz;
    int cz;
    vector<int> dx;
    vector<int> dy;
    queue<pair<int,int>> q;
};