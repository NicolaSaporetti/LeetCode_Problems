#include <vector>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int rz = matrix.size();
        int cz = matrix[0].size();
        vector<int> res(rz*cz,0);
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                if(i>0) matrix[i][j]^=matrix[i-1][j];
                if(j>0) matrix[i][j]^=matrix[i][j-1];
                if(j>0 && i>0) matrix[i][j]^=matrix[i-1][j-1];
                res[i*cz+j]=matrix[i][j];
            }
        }
        sort(begin(res),end(res));
        return res[rz*cz-k];
    }
};