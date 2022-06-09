#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
    void log_high_horizontal(int row, int column, int row_index, int column_index, vector<vector<int>>& matrix)
    {
        cout<<"log_high_horizontal\nrow: "<<row<<"\ncolumn: "<<column<<"\nRow index: "<<row_index<<"\nColumn index: "<<column_index<<endl;
        if(row==0) return;
        for(int i=0;i<column;i++)
        {
            solution[z++]=matrix[row_index][column_index+i];
        }
        row--;
        row_index++; 
        column_index=column_index+column-1;
        for(int i=0; i< solution.size(); i++)
        {
            cout<<solution[i]<<" ";
        }
        cout<<endl;
        log_high_vertical(row,column,row_index,column_index,matrix);
    }
    void log_low_horizontal(int row, int column, int row_index, int column_index,vector<vector<int>>& matrix)
    {
        cout<<"log_low_horizontal\nrow: "<<row<<"\ncolumn: "<<column<<"\nRow index: "<<row_index<<"\nColumn index: "<<column_index<<endl;
        if(row==0) return;
        for(int i=0;i<column;i++)
        {
            solution[z++]=matrix[row_index][column_index-i];
        }
        row--;
        row_index--;
        column_index=column_index-column+1;
        for(int i=0; i< solution.size(); i++)
        {
            cout<<solution[i]<<" ";
        }
        cout<<endl;
        log_low_vertical(row,column,row_index,column_index,matrix);
    }
    void log_high_vertical(int row, int column, int row_index, int column_index, vector<vector<int>>& matrix)
    {
        cout<<"log_high_vertical\nrow: "<<row<<"\ncolumn: "<<column<<"\nRow index: "<<row_index<<"\nColumn index: "<<column_index<<endl;
        if(column==0) return;
        for(int i=0;i<row;i++)
        {
            solution[z++]=matrix[row_index+i][column_index];
        }
        column--;
        column_index--;
        row_index=row_index+row-1;
        for(int i=0; i< solution.size(); i++)
        {
            cout<<solution[i]<<" ";
        }
        cout<<endl;
        log_low_horizontal(row,column,row_index,column_index,matrix);
    }
    void log_low_vertical(int row, int column, int row_index, int column_index, vector<vector<int>>& matrix)
    {
        cout<<"log_low_vertical\nrow: "<<row<<"\ncolumn: "<<column<<"\nRow index: "<<row_index<<"\nColumn index: "<<column_index<<endl;
        if(column==0) return;
        for(int i=0;i<row;i++)
        {
            solution[z++]=matrix[row_index-i][column_index];
        }
        column--;
        column_index++;
        row_index=row_index-row+1;
        for(int i=0; i< solution.size(); i++)
        {
            cout<<solution[i]<<" ";
        }
        cout<<endl;
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

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> sol = solution.spiralOrder(matrix);
    for(int i=0; i< sol.size(); i++)
    {
        cout<<sol[i]<<" ";
    }
    cout<<endl;
    return 0;
}