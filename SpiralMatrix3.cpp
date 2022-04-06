#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
    int calculateIterations(int rows, int cols, int rStart, int cStart)
    {
        int maxRow = max(rows-rStart,rStart);
        int maxColumn = max(cols-cStart,cStart);
        return max(maxRow,maxColumn);
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> solution;
        vector<int> element;
        int iteration = calculateIterations(rows,cols,rStart,cStart);
        cout<<iteration<<endl;
        int tempRow=rStart;
        int tempCol=cStart;
        element.push_back(tempRow);
        element.push_back(tempCol);
        solution.push_back(element);
        tempRow--;
        tempCol++;
        for(int i=1;i<iteration;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                tempRow++;
                if(tempCol>=0 && tempCol<cols && tempRow+j>=0 && tempRow+j<rows)
                {
                    element.push_back(tempRow);
                    element.push_back(tempCol);
                    solution.push_back(element);
                }
            }
            for(int j=0;j<i+1;j++)
            {
                tempCol--;
                if(tempCol-j>=0 && tempCol-j<cols && tempRow>=0 && tempRow<rows)
                {
                    element.push_back(tempRow);
                    element.push_back(tempCol);
                    solution.push_back(element);
                }
            }
            for(int j=0;j<i+1;j++)
            {
                tempRow--;
                if(tempCol>=0 && tempCol<cols && tempRow-j>=0 && tempRow-j<rows)
                {
                    element.push_back(tempRow);
                    element.push_back(tempCol);
                    solution.push_back(element);
                }
            }
            for(int j=0;j<i+1;j++)
            {
                tempCol++;
                if(tempCol+j>=0 && tempCol+j<cols && tempRow>=0 && tempRow<rows)
                {
                    element.push_back(tempRow);
                    element.push_back(tempCol);
                    solution.push_back(element);
                }
            }
        }
        return solution;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = solution.spiralMatrixIII(5,5,2,2);
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