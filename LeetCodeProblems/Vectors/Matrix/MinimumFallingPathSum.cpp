#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int result = INT_MAX;
        int row_sz = matrix.size();
        int col_sz = matrix[0].size();
        for(int i=1;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                int temp = matrix[i-1][j];
                if(j-1>=0) temp = min(temp,matrix[i-1][j-1]);
                if(j+1<col_sz) temp = min(temp,matrix[i-1][j+1]);
                matrix[i][j] += temp;
            }
        }
        for(int i=0;i<col_sz;i++) result = min(result, matrix[row_sz-1][i]);
        return result;
    }
};