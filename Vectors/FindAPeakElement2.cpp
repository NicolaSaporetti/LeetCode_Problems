#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> result;
        int i = 0;
        int j = 0;
        bool maxFound = false;
        int row_sz = mat.size();
        int col_sz = mat[0].size();
        while(!maxFound)
        {
            if(i>0 && mat[i-1][j]>mat[i][j]) i--;
            else if(i<row_sz-1 && mat[i+1][j]>mat[i][j]) i++;
            else if(j>0 && mat[i][j-1]>mat[i][j]) j--;
            else if(j<col_sz-1 && mat[i][j+1]>mat[i][j]) j++;
            else maxFound = true;
        }
        result.push_back(i);
        result.push_back(j);
        return result;
    }
};