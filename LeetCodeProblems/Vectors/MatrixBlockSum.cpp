#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int row_sz;
    int col_sz;
    
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int value = 0;
        row_sz = mat.size();
        col_sz = mat[0].size();
        vector<vector<int>> result(row_sz,vector<int>(col_sz,0));
        for(int i=0;i<=k-1 && i<row_sz;i++)
        {
            for(int j=0;j<=k && j<col_sz;j++)
            {
                value+=mat[i][j];
            }
        }
        int j=0;
        for(int i=0;i<row_sz;i++)
        {
            if(i-k-1>=0)
            {
                int start = max(j-k,0);
                int end = min(col_sz-1,j+k);
                for(int y=start;y<=end;y++)
                {
                    value-=mat[i-k-1][y];
                }
            }
            if(i+k<row_sz)
            {
                int start = max(j-k,0);
                int end = min(col_sz-1,j+k);
                for(int y=start;y<=end;y++)
                {
                    value+=mat[i+k][y];
                }
            }
            if(j==0)
            {
                for(j=0;j<col_sz;j++)
                {
                    if(j!=0)
                    {
                        if(j-k-1>=0)
                        {
                            int start = max(0,i-k);
                            int end = min(row_sz-1,i+k);
                            for(int y=start;y<=end;y++)
                            {
                                value-=mat[y][j-k-1];
                            }
                        }
                        if(j+k<col_sz)
                        {
                            int start = max(0,i-k);
                            int end = min(row_sz-1,i+k);
                            for(int y=start;y<=end;y++)
                            {
                                value+=mat[y][j+k];
                            }
                        }
                    }
                    result[i][j]=value;
                }
                j=col_sz-1;
            }
            else
            {
                for(j=col_sz-1;j>=0;j--)
                {
                    if(j!=col_sz-1)
                    {
                        if(j+k+1<col_sz)
                        {
                            int start = max(0,i-k);
                            int end = min(row_sz-1,i+k);
                            for(int y=start;y<=end;y++)
                            {
                                value-=mat[y][j+k+1];
                            }
                        }
                        if(j-k>=0)
                        {
                            int start = max(0,i-k);
                            int end = min(row_sz-1,i+k);
                            for(int y=start;y<=end;y++)
                            {
                                value+=mat[y][j-k];
                            }
                        }
                    }
                    result[i][j]=value;
                }
                j=0;
            }
        }
        return result;
    }
};