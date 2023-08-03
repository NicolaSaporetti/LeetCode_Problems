#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        int rz = isWater.size();
        int cz = isWater[0].size();
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++)
            {
                if(isWater[i][j]==1)
                {
                    q.push({i,j});
                    isWater[i][j]=0;
                }
                else isWater[i][j]=-1;
            }
        int h = 1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto el = q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nx = el.first+dx[j];
                    int ny = el.second+dy[j];
                    if(nx>=0 && nx<rz && ny>=0 && ny<cz && isWater[nx][ny]==-1)
                    {
                        q.push({nx,ny});
                        isWater[nx][ny]=h;
                    }
                }
            }
            h++;
        }
        return isWater;
    }
};