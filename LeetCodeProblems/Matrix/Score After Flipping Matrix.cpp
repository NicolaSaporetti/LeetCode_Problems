#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rz  = grid.size();
        int cz = grid[0].size();
        for(int i=0;i<rz;i++)
            if(grid[i][0]) for(int j=0;j<cz;j++) grid[i][j]=!grid[i][j];
        for(int j=0;j<cz;j++)
        {
            int t = 0;
            for(int i=0;i<rz;i++) t+=grid[i][j];
            if(t*2<rz) for(int i=0;i<rz;i++) grid[i][j] = !grid[i][j];
        }
        int r = 0;
        for(int i=0;i<rz;i++)
        {
            int v=0;
            for(int j=0;j<cz;j++)
            {
                v*=2;
                v+=grid[i][j];
            }
            r+=v;
        }
        return r;
    }
};