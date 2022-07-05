#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int row_sz;
    int col_sz;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int result = INT_MAX;
        row_sz = matrix.size();
        col_sz = matrix[0].size();
        for(int i=1;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(j-1>=0 && j+1<col_sz) matrix[i][j]+=min(matrix[i-1][j],min(matrix[i-1][j-1],matrix[i-1][j+1]));
                else if(j-1<0 && j+1>=col_sz) matrix[i][j]+=matrix[i-1][j];
                else if(j-1>=0 && j+1>=col_sz) matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j-1]);
                else matrix[i][j] += min(matrix[i-1][j],matrix[i-1][j+1]);
            }
        }
        for(int i=0;i<col_sz;i++)
        {
            result = min(result, matrix[row_sz-1][i]);
        }
        return result;
    }
};