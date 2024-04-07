#include <vector>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rz =grid.size();
        int cz = grid[0].size(); 
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                if(i>0) grid[i][j]+=grid[i-1][j];
                if(j>0) grid[i][j]+=grid[i][j-1];
                if(i>0 && j>0) grid[i][j]-=grid[i-1][j-1];
            }
        }
        int r = 0;
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                if(grid[i][j]<=k) r++;
                else break;
            }
        }
        return r;
    }
};