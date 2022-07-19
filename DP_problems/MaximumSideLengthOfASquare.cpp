#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row_sz = mat.size();
        int col_sz = mat[0].size();
        int result = 0;
        for(int i=0;i<row_sz;i++)
        {
            for(int j=1;j<col_sz;j++)
            {
                mat[i][j]+=mat[i][j-1];
            }
            if(i>0)
            {
                for(int j=0;j<col_sz;j++)
                {
                    mat[i][j]+=mat[i-1][j];
                }
            }
        }
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                int k=0;
                int maxK = min(row_sz-i,col_sz-j);
                if(maxK>result)
                {
                    for(;k<maxK;k++)
                    {
                        int value = mat[i+k][j+k];
                        if(i>0) value -= mat[i-1][j+k];
                        if(j>0) value -= mat[i+k][j-1];
                        if(j>0 && i>0) value += mat[i-1][j-1];
                        if(value>threshold) break;
                    }
                }
                result = max(result,k);
            }
        }
        return result;
    }
};