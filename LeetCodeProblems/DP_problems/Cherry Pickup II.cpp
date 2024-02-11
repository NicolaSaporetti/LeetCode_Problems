#include <vector>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        rz = grid.size();
        cz = grid[0].size();
        dp.assign(rz,vector<vector<int>>(cz,vector<int>(cz,-1)));
        return compute(0,0,cz-1,grid);
    }
private:
    int compute(int r, int c1, int c2, vector<vector<int>>& grid)
    {
        if(r>=rz || c1<0 || c2>=cz || c1>=c2) return 0;
        else if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        else
        {
            int val = grid[r][c1]+grid[r][c2];
            int maxV = 0;
            for(int i=-1;i<2;i++)
                for(int j=-1;j<2;j++)
                {
                    maxV = max(maxV,compute(r+1,c1+i,c2+j,grid));
                }
            return dp[r][c1][c2]=val+maxV;
        }
    }

    vector<vector<vector<int>>> dp;
    int rz;
    int cz;
};