#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int rz = grid.size();
        int cz = grid[0].size();
        vector<long long> s(rz*cz,0);
        vector<vector<int>> res(rz,vector<int>(cz,0));
        long long t = 1;
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                t*=(long long)grid[i][j];
                t%=mod;
                s[i*cz+j]=t;
            }
        }
        t = 1;
        for(int i=rz-1;i>=0;i--)
        {
            for(int j=cz-1;j>=0;j--)
            {
                if(i==0 && j==0) res[i][j] = t;
                else res[i][j]= (t*s[i*cz+j-1])%mod;
                t*=(long long)grid[i][j];
                t%=mod;
            }
        }
        return res;
    }
};