#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rz = mat.size();
        int cz = mat[0].size();
        if(r*c!=rz*cz) return mat;
        else
        {
            vector<vector<int>> result(r,vector<int>(c,0));
            int pos = 0;
            int oldRow = 0;
            int oldCol = 0;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    result[i][j] = mat[oldRow][oldCol++];
                    if(oldCol==cz)
                    {
                        oldCol=0;
                        oldRow++;
                    }
                }
            }
            return result;
        }
    }
};