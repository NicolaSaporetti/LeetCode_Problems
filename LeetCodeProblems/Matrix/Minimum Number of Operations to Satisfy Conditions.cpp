#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        vector<vector<int>> v(cz,vector<int>(10,rz));
        for(int i=0;i<cz;i++)
            for(int j=0;j<rz;j++) v[i][grid[j][i]]--;
        for(int i=cz-2;i>=0;i--)
        {
            for(int j=0;j<10;j++)
            {
                int r = INT_MAX;
                for(int z=0;z<10;z++)
                {
                    if(z==j) continue;
                    r=min(r,v[i+1][z]);
                }
                v[i][j]+=r;
            }
        }
        int r = INT_MAX;
        for(int i=0;i<10;i++) r=min(r,v[0][i]);
        return r;
    }
};