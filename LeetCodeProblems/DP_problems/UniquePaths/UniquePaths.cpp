#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i!=1 && j!=1)  matrix[i][j]=matrix[i-1][j]+matrix[i][j-1];
                else matrix[i][j]=1;
            }
        }
        return matrix[m][n];
    }
};