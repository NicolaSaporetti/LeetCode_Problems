#include <vector>
#include <queue>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        sz = grid.size();
        changeGrid(grid);
        return computeRes(grid);
    }
private:
    void changeGrid(vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
            {
                if(grid[i][j]==0) grid[i][j]=-1;
                else
                {
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        int d = 1;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto el = q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nx = el.first+dx[j];
                    int ny = el.second+dy[j];
                    if(nx>=0 && nx<sz && ny>=0 && ny<sz && grid[nx][ny]==-1)
                    {
                        grid[nx][ny]=d;
                        q.push({nx,ny});
                    }
                }
            }
            d++;
        }
    }
    int computeRes(vector<vector<int>>& grid)
    {
        priority_queue<vector<int>> pq;
        pq.push({grid[0][0],0,0});
        int res = grid[0][0];
        grid[0][0]=-1;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            res = min(res, el[0]);
            if(el[1]==sz-1 && el[2]==sz-1) return res;
            for(int j=0;j<4;j++)
            {
                int nx = el[1]+dx[j];
                int ny = el[2]+dy[j];
                if(nx>=0 && nx<sz && ny>=0 && ny<sz && grid[nx][ny]!=-1)
                {
                    pq.push({grid[nx][ny],nx,ny});
                    grid[nx][ny]=-1;
                }
            }
        }
        return res;
    }
    
    int sz;
};