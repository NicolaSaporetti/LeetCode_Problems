#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rz = matrix.size();
        cz = matrix[0].size();
        ri = {1,-1,0,0};
        ci = {0,0,1,-1};
        dp.assign(rz,vector<int>(cz,-1));
        int maxE = 0;
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                maxE = max(maxE,1+checkGreater(matrix,i,j));
            }
        }
        return maxE;
    }
    
private:
    int checkGreater(vector<vector<int>>& matrix, int r, int c)
    {
        if(dp[r][c]!=-1) return dp[r][c];
        else
        {
            int maxS = 0;
            for(int i=0;i<4;i++)
            {
                int newr = r+ri[i];
                int newc = c+ci[i];
                if(newr>=0 && newr<rz && newc>=0 && newc<cz && matrix[newr][newc]>matrix[r][c])
                {
                    maxS = max(maxS,1+checkGreater(matrix,newr,newc));
                }
            }
            dp[r][c]=maxS;
            return maxS;
        }
    }
    
    int rz;
    int cz;
    vector<int> ri;
    vector<int> ci;
    vector<vector<int>> dp;
};