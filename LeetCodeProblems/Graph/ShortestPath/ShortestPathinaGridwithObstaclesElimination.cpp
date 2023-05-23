#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        rz = grid.size();
        cz = grid[0].size();
        dx = {1,-1,0,0};
        dy = {0,0,1,-1};
        q.push({0,0,0,0});
        obstaclesRemoved.assign(rz, vector<int>(cz, INT_MAX));
        obstaclesRemoved[0][0] = 0;
        return computeShortestPath(grid,k);
    }
    
private:
    int computeShortestPath(vector<vector<int>>& grid, int k)
    {
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            int x = node[0];
            int y = node[1];
            int obstacles = node[2];
            int dist = node[3];
            if (x == rz-1 && y == cz-1) return dist;
            
            for (int i = 0; i<4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if (nx < 0 || nx>=rz || ny <0 || ny>=cz) continue;
                int newObstacles = obstacles+grid[nx][ny];
                if(newObstacles>k || obstaclesRemoved[nx][ny]<=newObstacles) continue;
                obstaclesRemoved[nx][ny]=newObstacles;
                q.push({nx,ny,newObstacles,dist+1});
            }
        }
        return -1;
    }
    
    int rz;
    int cz;
    queue<vector<int>> q;
    vector<vector<int>> obstaclesRemoved;
    vector<int> dx;
    vector<int> dy;
};