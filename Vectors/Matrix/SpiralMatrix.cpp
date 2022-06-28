#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void log_high_horizontal(int row, int column, int row_index, int column_index, vector<vector<int>>& matrix)
    {
        if(row==0) return;
        for(int i=0;i<column;i++)
        {
            solution[z++]=matrix[row_index][column_index+i];
        }
        row--;
        row_index++; 
        column_index=column_index+column-1;
        log_high_vertical(row,column,row_index,column_index,matrix);
    }
    void log_low_horizontal(int row, int column, int row_index, int column_index,vector<vector<int>>& matrix)
    {
        if(row==0) return;
        for(int i=0;i<column;i++)
        {
            solution[z++]=matrix[row_index][column_index-i];
        }
        row--;
        row_index--;
        column_index=column_index-column+1;
        log_low_vertical(row,column,row_index,column_index,matrix);
    }
    void log_high_vertical(int row, int column, int row_index, int column_index, vector<vector<int>>& matrix)
    {
        if(column==0) return;
        for(int i=0;i<row;i++)
        {
            solution[z++]=matrix[row_index+i][column_index];
        }
        column--;
        column_index--;
        row_index=row_index+row-1;
        log_low_horizontal(row,column,row_index,column_index,matrix);
    }
    void log_low_vertical(int row, int column, int row_index, int column_index, vector<vector<int>>& matrix)
    {
        if(column==0) return;
        for(int i=0;i<row;i++)
        {
            solution[z++]=matrix[row_index-i][column_index];
        }
        column--;
        column_index++;
        row_index=row_index-row+1;
        log_high_horizontal(row,column,row_index,column_index,matrix);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        z=0;
        solution.resize(n*m);
        log_high_horizontal(n,m,0,0,matrix);
        return solution;
    }
    vector<int> solution;
    int z;
};