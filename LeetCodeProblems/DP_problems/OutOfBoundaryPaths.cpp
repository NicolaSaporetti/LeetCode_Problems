#include <vector>
using namespace std;

class Solution {
public:    

    int findPaths(int m, int n, int N, int i, int j) {
        rz = m;
        cz = n;
        mod = 1000000007;
        res = 0;
        vector<vector<vector<int>>> memo(rz,vector(cz,vector(N+1,0)));
        memo[i][j][N]=1;
        findPaths(N, i, j, memo);
        return res;
    }

    void findPaths(int N, int r, int c, vector<vector<vector<int>>>& memo) {
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int z=N;z>0;z--)
        {
            for(int i=0;i<rz;i++)
            {
                for(int j=0;j<cz;j++)
                {
                    if(memo[i][j][z]>0)
                    {
                        for(int k=0;k<4;k++)
                        {
                            int nx = i+dx[k];
                            int ny = j+dy[k];
                            if(nx<0 || nx>=rz || ny<0 || ny>=cz) res=(res+memo[i][j][z])%mod;
                            else memo[nx][ny][z-1]=(memo[nx][ny][z-1]+memo[i][j][z])%mod;
                        }
                    }
                }
            }
        }
    }

private:
    int rz;
    int cz;
    int mod = 1000000007;
    int res;
};