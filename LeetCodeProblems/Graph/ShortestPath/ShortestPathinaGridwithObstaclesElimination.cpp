#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node
{
    int x;
    int y;
    int dist;
    int obstacleToRemove;
} Node;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        q.push({0,0,0,k});
        vis.assign(n, vector<int>(m, -1));
        vis[0][0] = k;
        return computeShortestPath(grid,k);
    }
    
private:
    int computeShortestPath(vector<vector<int>>& grid, int k)
    {
        int answer = -1;        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while(!q.empty())
        {
            Node node = q.front();
            q.pop();
            
            int x = node.x;
            int y = node.y;
            int dist = node.dist;
            int obstacleToRemove = node.obstacleToRemove;
            if (x == n-1 && y == m-1) return dist;
            
            for (int i = 0; i<4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if (nx < 0 || nx>=n || ny <0 || ny>=m || (vis[nx][ny]!=-1 && vis[nx][ny]>=obstacleToRemove-grid[nx][ny]) || grid[nx][ny]>obstacleToRemove)
                    continue;
                q.push({nx,ny,dist+1,obstacleToRemove-grid[nx][ny]});
                vis[nx][ny] = obstacleToRemove-grid[nx][ny];
            }
            //printV();
        }
        return answer;
    }
    
    void printV()
    {
        for(auto x : vis)
        {
            for(auto y : x) cout<<y<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    
    int n;
    int m;
    queue<Node> q;
    vector<vector<int>> vis;
};