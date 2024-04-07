#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        if(m*n!=original.size()) return {};
        int pos = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=original[pos++];
            }
        }
        return matrix;
    }
};