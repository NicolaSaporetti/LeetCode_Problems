#include <priority_queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        pq.push({grid[0][0], {0, 0}});
        vis.assign(n, vector<int>(m, 0));
        vis[0][0] = true;
        return computeMinPathSum(grid);
    }
    
private:
    int computeMinPathSum(vector<vector<int>>& grid)
    {
        int answer = 0;        
        vector<int> dx= {0, 1};
        vector<int> dy={1, 0};
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
            
            for (int i = 0; i<2; i++)
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
    
private:
    
    int n;
    int m;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> vis;
};