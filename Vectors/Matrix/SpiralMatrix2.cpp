#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        int number = 1;
        matrix.resize(n);
        for(int j=0;j<n;j++)
        {
            matrix[j].resize(n);
        }
        for(int j=0;j<(n+1)/2;j++)
        {
            if(n-2*j == 1)
            {
                matrix[j][j] = number++;
            }
            else{
                for(int i=0;i<n-1-2*j;i++)
                {
                    matrix[j][i+j]=number++;
                }
                for(int i=0;i<n-1-2*j;i++)
                {
                    matrix[i+j][n-1-j]=number++;
                }
                for(int i=0;i<n-1-2*j;i++)
                {
                    matrix[n-1-j][n-1-i-j]=number++;
                }
                for(int i=0;i<n-1-2*j;i++)
                {
                    matrix[n-1-i-j][j]=number++;
                }
            }
        }
        return matrix;
    }
};