#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        rz=heights.size();
        cz=heights[0].size();
        grid.assign(rz,vector<bool>(cz,false));
        pq.push({0,0,0});
        int d = 0;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            d = max(el[0],d);
            int x = el[1];
            int y = el[2];
            if(grid[x][y]) continue;
            if(x==rz-1 && y ==cz-1) return d;
            grid[x][y]=true;
            int h = heights[x][y];
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || nx>=rz || ny<0 || ny>=cz || grid[nx][ny]) continue;
                int nh = heights[nx][ny];
                pq.push({abs(nh-h),nx,ny});
            }
        }
        return d;
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
private:
    vector<vector<bool>> grid;
    int rz;
    int cz;
};