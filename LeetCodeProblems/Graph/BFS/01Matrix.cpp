#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rz = mat.size();
        int cz = mat[0].size();
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rz,vector<bool>(cz,false));
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++) if(mat[i][j]==0)
            {
                q.push({i,j});
                visited[i][j]=true;
            }
        }
        int dist = 1;
        while(!q.empty())
        {
            int num = q.size();
            for(int i=0;i<num;i++)
            {
                auto el = q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nx = el.first+dx[j];
                    int ny = el.second+dy[j];
                    if(nx<0 || nx>=rz || ny<0 || ny>=cz || visited[nx][ny]) continue;
                    mat[nx][ny]=dist;
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
            dist++;
        }
        return mat;
    }
};