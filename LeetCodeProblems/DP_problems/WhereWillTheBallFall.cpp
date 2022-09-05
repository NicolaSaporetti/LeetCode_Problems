#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        rz = grid.size();
        cz = grid[0].size();
        mat.assign(rz,vector<int>(cz,-2));
        for(int i=0;i<cz;i++)
        {
            mat[0][i] = getPos(grid,0,i);
        }
        return mat[0];
    }
private:
    int getPos(vector<vector<int>>& grid, int i, int j)
    {
        if(i>=rz) return j;
        else if(mat[i][j]==-2)
        {
            if(grid[i][j]==1)
            {
                if(j+1>=cz || grid[i][j+1]==-1) mat[i][j]=-1;
                else mat[i][j]=getPos(grid,i+1,j+1);
            }
            else
            {
                if(j-1<0 || grid[i][j-1]==1) mat[i][j]=-1;
                else mat[i][j]=getPos(grid,i+1,j-1);
            }
        }
        return mat[i][j];
    }
    
    vector<vector<int>> mat;
    int rz;
    int cz;
};