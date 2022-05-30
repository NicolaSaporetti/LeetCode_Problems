#include <iostream>
#include <stdlib.h>
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

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution solution;
    solution.rotate(matrix);
    for(int i=0; i< matrix.size(); i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}