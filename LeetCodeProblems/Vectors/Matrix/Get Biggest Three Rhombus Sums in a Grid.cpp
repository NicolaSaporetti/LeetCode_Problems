#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        set<int> results;
        vector<int> res;
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                for(int k=0;i+k<rz && i-k>=0 && j+k<cz && j-k>=0;k++)
                {
                    results.insert(computeRombus(i,j,k,grid));
                }
            }
        }
        auto it = results.rbegin();
        for(int i=0;i<3 && it!=results.rend();i++)
        {
            res.push_back(*it);
            it++;
        }
        return res;
    }
private:
    int computeRombus(int r, int c, int k, vector<vector<int>>& grid)
    {
        if(k==0) return grid[r][c];
        else
        {
            int res = grid[r][c-k]+grid[r][c+k];
            int j=1;
            for(int i=c-k+1;i<=c;i++,j++)
            {
                res+=grid[r+j][i];
                res+=grid[r-j][i];
            }
            j=1;
            for(int i=c+k-1;i>c;i--,j++)
            {
                res+=grid[r+j][i];
                res+=grid[r-j][i];
            }
            return res;
        }
    }
    
};