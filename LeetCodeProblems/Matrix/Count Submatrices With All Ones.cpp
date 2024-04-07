#include <vector>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rz = mat.size();
        int cz = mat[0].size();
        for(int i=0;i<rz;i++)
            for(int j=cz-2;j>=0;j--)
            {
                if(mat[i][j]==1 && mat[i][j+1]>=1) mat[i][j]=mat[i][j+1]+1;
            }
        int r = 0;
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                int v = INT_MAX;
                for(int k=i;k<rz;k++)
                {
                    if(mat[k][j]==0) break;
                    if(k==i) v = mat[k][j];
                    else v = min(v,mat[k][j]);
                    r+=v;
                }
            }
        }
        return r;
    }
};