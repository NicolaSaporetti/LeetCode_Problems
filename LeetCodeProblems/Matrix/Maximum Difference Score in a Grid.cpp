#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        vector<vector<int>> r = grid;
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++)
            {
                if(i>0 && j>0) grid[i][j]=min(grid[i][j],min(grid[i-1][j],grid[i][j-1]));
                else if(i>0) grid[i][j]=min(grid[i][j],grid[i-1][j]);
                else if(j>0) grid[i][j]=min(grid[i][j],grid[i][j-1]);
            }
        int r2 = INT_MIN;
        for(int i=0;i<rz;i++)
        {
            int v = grid[i][0];
            for(int j=1;j<cz;j++)
            {
                r2 = max(grid[i][j]-v,r2);
                v = min(v,grid[i][j]);
            }
        }
        for(int i=0;i<cz;i++)
        {
            int v = grid[0][i];
            for(int j=1;j<rz;j++)
            {
                r2 = max(grid[j][i]-v,r2);
                v = min(v,grid[j][i]);
            }
        }
        int r1 = INT_MIN;
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++)
            {
                r1 = max(r[i][j]-grid[i][j],r1);
            }
        return (r1==0)? r2 : r1;
    }
};