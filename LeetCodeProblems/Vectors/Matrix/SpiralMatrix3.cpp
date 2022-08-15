#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int calculateIterations(int rows, int cols, int rStart, int cStart)
    {
        int maxRow = max(rows-rStart,rStart+1);
        int maxColumn = max(cols-cStart,cStart+1);
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
            for(int j=0;j<2*i;j++)
            {
                tempRow++;
                if(tempCol>=0 && tempCol<cols && tempRow>=0 && tempRow<rows)
                {
                    element[0]=tempRow;
                    element[1]=tempCol;
                    solution.push_back(element);
                }
            }
            for(int j=0;j<2*i;j++)
            {
                tempCol--;
                if(tempCol>=0 && tempCol<cols && tempRow>=0 && tempRow<rows)
                {
                    element[0]=tempRow;
                    element[1]=tempCol;
                    solution.push_back(element);
                }
            }
            for(int j=0;j<2*i;j++)
            {
                tempRow--;
                if(tempCol>=0 && tempCol<cols && tempRow>=0 && tempRow<rows)
                {
                    element[0]=tempRow;
                    element[1]=tempCol;
                    solution.push_back(element);
                }
            }
            for(int j=0;j<2*i;j++)
            {
                tempCol++;
                if(tempCol>=0 && tempCol<cols && tempRow>=0 && tempRow<rows)
                {
                    element[0]=tempRow;
                    element[1]=tempCol;
                    solution.push_back(element);
                }
            }
            tempRow--;
            tempCol++;
        }
        return solution;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = solution.spiralMatrixIII(5,6,1,4);
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