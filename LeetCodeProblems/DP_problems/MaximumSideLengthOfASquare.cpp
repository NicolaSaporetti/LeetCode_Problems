#include <vector>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rz = mat.size();
        int cz = mat[0].size();
        vector<vector<int>> m(rz+1,vector<int>(cz+1,0));
        int result = 0;
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) m[i+1][j+1]=mat[i][j]+m[i+1][j]+m[i][j+1]-m[i][j];
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++)
            {
                int maxK = min(rz-i,cz-j);
                if(maxK>result)
                {
                    for(int k=1;k<=maxK;k++)
                    {
                        int value = m[i+k][j+k];
                        value -= m[i][j+k];
                        value -= m[i+k][j];
                        value += m[i][j];
                        if(value>threshold) break;
                        result = max(result,k);
                    }
                }
            }
        return result;
    }
};