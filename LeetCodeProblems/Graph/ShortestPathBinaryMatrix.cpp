#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        initialize(grid);
        if(grid[0][0] || grid[sz-1][sz-1]) return -1;
        int dist = 1;
		while(!q.empty())
        {
            int num = q.size();
            for(int i=0;i<num;i++)
            {
                auto el = q.front();
                q.pop();
                if(el.first==sz-1 && el.second==sz-1) return dist;
                for(int j=0;j<8;j++)
                {
                    int nx = el.first+dx[j];
                    int ny = el.second+dy[j];
                    if(nx<0 || nx>=sz || ny<0 || ny>=sz || visited[nx][ny] || grid[nx][ny]!=0) continue;
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
            dist++;
        }
        return -1;
    }

private:
    void initialize(vector<vector<int>>& grid)
    {
        sz = grid.size();
        q.push({0,0});
        visited.assign(sz,vector<bool>(sz,false));
        visited[0][0]=true;
        dx = {1,1,1,0,-1,-1,-1,0};
        dy = {-1,0,1,1,1,0,-1,-1};
    }

    int sz;
    vector<vector<bool>> visited;
    queue<pair<int,int>> q;
    vector<int> dx;
    vector<int> dy;
};