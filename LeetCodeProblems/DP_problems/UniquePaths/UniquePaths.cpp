#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void initialize_board(int m, int n)
    {
        matrix.resize(m);
        for(int i=0;i<matrix.size();i++)
        {
            matrix[i].resize(n);
            matrix[i][0]=1;
        }
        for(int i=0;i<matrix[0].size();i++)
        {
            matrix[0][i]=1;
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[i].size();j++)
            {
                matrix[i][j]=matrix[i-1][j]+matrix[i][j-1];
            }
        }
    }
public:
    int uniquePaths(int m, int n) {
        initialize_board(m,n);
        return matrix[m-1][n-1];
    }
    vector<vector<int>> matrix;
};