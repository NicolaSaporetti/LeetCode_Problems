#include <vector>
using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        rz = grid.size();
        cz = grid[0].size();
        int res = 1;
        vector<vector<int>> rowS(rz,vector<int>(cz+1,0));
        vector<vector<int>> colS(rz+1,vector<int>(cz,0));
        computeRowS(grid,rowS);
        computeColS(grid,colS);
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                for(int k=2;i+k-1<rz && j+k-1<cz;k++)
                {
                    if(isEqual(i,j,k,rowS,colS,grid)) res = max(res,k);
                }
            }
        }
        return res;
    }
private:
    void computeRowS(vector<vector<int>>& grid, vector<vector<int>>& r)
    {
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                r[i][j+1] = r[i][j]+grid[i][j];
            }
        }
    }
    void computeColS(vector<vector<int>>& grid, vector<vector<int>>& c)
    {
        for(int i=0;i<cz;i++)
        {
            for(int j=0;j<rz;j++)
            {
                c[j+1][i] = c[j][i]+grid[j][i];
            }
        }
    }
    bool isEqual(int r, int c, int k, vector<vector<int>>& rg, vector<vector<int>>& cg, vector<vector<int>>& grid)
    {
        int val = rg[r][c+k]-rg[r][c];
        for(int i=1;i<k;i++)
        {
            if(rg[r+i][c+k]-rg[r+i][c]!=val) return false;
        }
        for(int i=0;i<k;i++)
        {
            if(cg[r+k][c+i]-cg[r][c+i]!=val) return false;
        }
        int res =0;
        for(int i=0;i<k;i++) res+=grid[r+i][c+i];
        if(res!=val) return false;
        res = 0;
        for(int i=0;i<k;i++) res+=grid[r+k-i-1][c+i];
        if(res!=val) return false;
        return true;
    }
    
    int rz;
    int cz;
};