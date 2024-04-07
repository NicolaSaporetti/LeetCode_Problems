#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rz = mat.size();
        int cz = mat[0].size();
        vector<vector<int>> res(rz,vector<int>(cz,0));
        vector<vector<int>> dp(rz+1,vector<int>(cz+1,0));
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]-dp[i][j]+mat[i][j];
            }
        }
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                res[i][j]=dp[min(i+k+1,rz)][min(j+k+1,cz)]-dp[min(i+k+1,rz)][max(j-k,0)]-dp[max(0,i-k)][min(j+k+1,cz)]+dp[max(0,i-k)][max(j-k,0)];
            }
        }
        return res;
    }
};