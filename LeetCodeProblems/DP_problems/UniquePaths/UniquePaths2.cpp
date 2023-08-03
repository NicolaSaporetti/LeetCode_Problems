#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> matrix(m+1,vector<int>(n+1,0));
        matrix[0][1]=1;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(obstacleGrid[i-1][j-1]==1) matrix[i][j] = 0;
                else matrix[i][j]=matrix[i-1][j]+matrix[i][j-1];
            }
        }
        return matrix[m][n];
    }
};