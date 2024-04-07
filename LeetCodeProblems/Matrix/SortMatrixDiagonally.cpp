#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        rz=mat.size();
        cz=mat[0].size();
        for(int i=rz-1;i>=0;i--)
        {
            orderDiagonal(mat,i,0);
        }
        for(int i=1;i<cz;i++)
        {
            orderDiagonal(mat,0,i);
        }
        return mat;
    }
private:
    void orderDiagonal(vector<vector<int>>& mat, int row, int col)
    {
        vector<int> temp;
        for(int i=0;row+i<rz && col+i<cz;i++)
        {
            temp.push_back(mat[row+i][col+i]);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;row+i<rz && col+i<cz;i++)
        {
            mat[row+i][col+i]=temp[i];
        }
    }
    
    int rz;
    int cz;
};