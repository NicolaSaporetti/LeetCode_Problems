#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        int mod = 12345;
        vector<vector<int>> res(rz,vector<int>(cz));
        vector<long long> l(rz*cz+1,1);
        vector<long long> r(rz*cz+1,1);
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                l[i*cz+j+1]=(l[i*cz+j]*grid[i][j])%mod;
            }
        }
        for(int i=rz-1;i>=0;i--)
        {
            for(int j=cz-1;j>=0;j--)
            {
                r[i*cz+j]=(r[i*cz+j+1]*grid[i][j])%mod;
                res[i][j]=(r[i*cz+j+1]*l[i*cz+j])%mod;
            }
        }
        return res;
    }
};