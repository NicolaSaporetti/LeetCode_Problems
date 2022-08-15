#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> newMat (matrix.size()*matrix.size(),0);
        int pos = 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                newMat[pos++] = matrix[i][j];
            }
        }
        sort(newMat.begin(),newMat.end());
        return newMat[k-1];
    }
};