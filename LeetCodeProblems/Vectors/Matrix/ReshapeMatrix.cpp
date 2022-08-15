#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> result(r,vector<int>(c,0));
        int oldRowSz = mat[0].size();
        if(r*c!=oldRowSz*mat.size()) return mat;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int elem = c*i+j;
                int oldRow = elem/oldRowSz;
                int oldCol = elem-oldRow*oldRowSz;
                result[i][j] = mat[oldRow][oldCol];
            }
        }
        return result;
    }
};