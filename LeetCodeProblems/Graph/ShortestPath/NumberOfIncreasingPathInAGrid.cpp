#include <vector>
using namespace std;

class Solution {    
public:
    int countPaths(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        dp.assign(rows,vector<int>(cols,0));
        hor = {1,-1,0,0};
        ver = {0,0,1,-1};
        comb = 0;
        mod = 1000000007;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                comb = (comb+get_comb_number(i,j, grid))%mod;
            }
        }
        return comb;
    }
    
private:
    int rows;
    int cols;
    int mod;
    long long comb;
    vector<int> ver;
    vector<int> hor;
    vector<vector<int>> dp;
    
    int get_comb_number(int r,int c, vector<vector<int>>& grid)
    {
        if(dp[r][c]!=0) return dp[r][c];
        else
        {
            int res = 1;
            for(int i=0;i<4;i++)
            {
                int nr=r+ver[i];
                int nc=c+hor[i];
                if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]>grid[r][c])
                {
                    res= (res+get_comb_number(nr,nc,grid))%mod;
                }
            }
            return dp[r][c]=res;
        }
    }
};