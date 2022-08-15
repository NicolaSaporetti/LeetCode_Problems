#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
int sz;
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==1) return;
        else{
            sz=matrix.size();
            int temp[4] = {0};
            for(int j=0;j<sz/2;j++)
            {
                for(int i=0;i<sz-1-2*j;i++)
                {
                    temp[0]= matrix[i+j][sz-1-j];
                    matrix[i+j][sz-1-j] = matrix[j][i+j];

                    temp[1]= matrix[sz-1-j][sz-1-i-j];
                    matrix[sz-1-j][sz-1-i-j] = temp[0];

                    temp[2]= matrix[sz-1-i-j][j];
                    matrix[sz-1-i-j][j] = temp[1];
                    
                    matrix[j][i+j] = temp[2];
                }
            }
        }
    }
};