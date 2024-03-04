#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        pq.push({0, {0, 0}});
        vis.resize(n, vector<int>(m, 0));
        vis[0][0] = 1;
        return computeShortestPath(grid);
    }
    
private:
    int computeShortestPath(vector<vector<int>>& grid)
    {
        int answer = 0;        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            
            int cost = node.first;
            answer = cost;
            int x = node.second.first;
            int y = node.second.second;
            if (x == n-1 && y == m-1)
                break;
            
            for (int i = 0; i<4; i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if (nx < 0 || nx>=n || ny <0 || ny>=m || vis[nx][ny] == 1)
                    continue;
                pq.push({cost+grid[nx][ny], {nx, ny}});
                vis[nx][ny] = 1;
            }
        }
        return answer;
    }
    
    int n;
    int m;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> vis;
};