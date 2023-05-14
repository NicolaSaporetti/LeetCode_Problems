#include <vector>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        rz = grid.size();
        cz = grid[0].size();
        dx = {1,-1,0};
        dy = {1,1,1};
        dist.assign(rz,vector<int>(cz,-1));
        int res = 0;
        for(int j=0;j<rz;j++)
        {
            res = max(res,computeDepth(j,0,grid));
        }
		return res-1;
    }

private:
    int computeDepth(int r, int c, vector<vector<int>>& grid) {
        if(dist[r][c]!=-1) return dist[r][c];
        else if(c==cz-1) return 1;
        else
        {
            int res = 0;
            for(int i=0;i<3;i++)
            {
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr<rz && nr>=0 && grid[nr][nc]>grid[r][c]) res = max(res,computeDepth(nr,nc,grid));
            }
            dist[r][c]=1+res;
            return dist[r][c];
        }
    }

    int rz;
    int cz;
    vector<int> dx;
    vector<int> dy;
    vector<vector<int>> dist;
};