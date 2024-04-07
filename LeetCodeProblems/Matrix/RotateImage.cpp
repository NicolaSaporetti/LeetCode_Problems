#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n/2;i++)
        {
            for (int j=0; j<n-1-2*i; j++){
                int t = matrix[i][i+j];
                matrix[i][i+j] = matrix[n-i-1-j][i];
                matrix[n-i-1-j][i] =  matrix[n-i-1][n-i-1-j];
                matrix[n-i-1][n-i-1-j] = matrix[i+j][n-i-1];
                matrix[i+j][n-i-1] = t;
            }
        }
    }
};