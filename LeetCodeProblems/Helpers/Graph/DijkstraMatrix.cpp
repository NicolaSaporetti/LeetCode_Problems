#include <vector>
#include <priority_queue>
using namespace std;

vector<vector<int>> dijkstra(vector<vector<int>>& mat)
{
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};
    int rz = mat.size();
    int cz = mat[0].size();
    vector<vector<int>> dist(rz,vector<int>(cz,-1));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0,0,0});
    while (!pq.empty()) {
        auto el = pq.top();
        pq.pop();
        int cost = el[0];
        int row = el[1];
        int col = el[2];
        if(dist[row][col]!=-1) continue;
        dist[row][col]=cost;
        for (int i=0;i<4;i++) {
            int newRow = row+dx[i];
            int newCol = col+dy[i];
            int newCost = cost+mat[row][col];
            if(newRow<0 || newRow>=rz || newCol<0 || newCol>=cz || dist[newRow][newCol]!=-1) continue;
            pq.push({newCost,newRow,newCol});
        }
    }
    return dist;
}