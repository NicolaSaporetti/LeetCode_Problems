#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int result = 0;
        for(int i=0;i<mat.size();i++)
        {
            result+=mat[i][i];
            result+=mat[mat.size()-1-i][i];
        }
        if(mat.size()%2==1) result-=mat[mat.size()/2][mat.size()/2];
        return result;
    }
};