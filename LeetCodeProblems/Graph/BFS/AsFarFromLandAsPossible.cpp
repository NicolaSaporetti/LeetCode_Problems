#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        rz = grid.size();
        cz = grid[0].size();
        dx = {1,-1,0,0};
        dy = {0,0,1,-1};
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                if(grid[i][j]==1) q.push({i,j});
            }
        }
		int value = computeDepth(grid);
        return (value==0)? -1 : value;
    }

private:
    int computeDepth(vector<vector<int>>& grid) {
        int depth = -1;
        while(!q.empty())
        {
            depth++;
            int num = q.size();
            for(int i=0;i<num;i++)
            {
                auto el = q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nx = el.first+dx[j];
                    int ny = el.second+dy[j];
                    if(nx>=0 && nx<rz && ny>=0 && ny<cz && grid[nx][ny]==0)
                    {
                        grid[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return depth;
    }

    int rz;
    int cz;
    queue<pair<int,int>> q;
    vector<int> dx;
    vector<int> dy;
};