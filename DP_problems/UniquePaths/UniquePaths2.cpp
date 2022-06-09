#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int column=obstacleGrid[0].size();
        obstacleGrid2.resize(row);
        for(int i=0;i<obstacleGrid2.size();i++)
        {
            obstacleGrid2[i].resize(column);
            obstacleGrid2[i][0]=1;
        }
        if(obstacleGrid[row-1][column-1]==1) return 0;
        else{
            obstacleGrid2[row-1][column-1]=1;
            if(column>=2)
            {
                for(int i=column-2;i>=0;i--)
                {
                    if(obstacleGrid[row-1][i]==1)
                    {
                        obstacleGrid2[row-1][i]=0;
                    }
                    else{
                        obstacleGrid2[row-1][i]=obstacleGrid2[row-1][i+1];
                    }
                }
            }
            if(row>=2)
            {
                for(int i=row-2;i>=0;i--)
                {
                    if(obstacleGrid[i][column-1]==1)
                    {
                        obstacleGrid2[i][column-1]=0;
                    }
                    else{
                        obstacleGrid2[i][column-1]=obstacleGrid2[i+1][column-1];
                    }
                }
            }
            if(row>=2 && column>=2)
            {
                for(int i=row-2;i>=0;i--)
                {
                    for(int j=column-2;j>=0;j--)
                    {
                        if(obstacleGrid[i][j]==1)
                        {
                            obstacleGrid2[i][j]=0;
                        }
                        else{
                            obstacleGrid2[i][j]=obstacleGrid2[i+1][j]+obstacleGrid2[i][j+1];
                        }
                    }
                }
            }
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    cout<<obstacleGrid2[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        return obstacleGrid2[0][0];
    }
    vector<vector<long long int>> obstacleGrid2;
};