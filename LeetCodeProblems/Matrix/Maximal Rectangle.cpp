#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& m) {
        int rz = m.size();
        int cz = m[0].size();
        vector<vector<int>> matrix(rz,vector<int>(cz,0));
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) matrix[i][j]=m[i][j]-'0';
        for(int i=0;i<rz;i++)
        {
            int v = 0;
            for(int j=cz-1;j>=0;j--)
            {
                if(matrix[i][j]>0)
                {
                    matrix[i][j]+=v;
                    v++;
                }
                else v = 0;
            }
        }
        int r = 0;
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++)
            {
                int maxl = INT_MAX;
                for(int k=i;k<rz;k++)
                {
                    if(matrix[k][j]==0) break;
                    maxl = min(maxl,matrix[k][j]);
                    r = max(maxl*(k-i+1),r);
                }
            }
        return r;
    }
};