#include <vector>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int r = 0;
        int rz = grid.size();
        int cz = grid[0].size();
        vector<vector<int>> mat(rz,vector<int>(cz));
        for(int i=1;i<cz;i++)
        {
            for(int j=0;j<rz;j++)
            {
                if(j>0 && grid[j][i]>grid[j-1][i-1]) mat[j][i]=max(mat[j][i],1+mat[j-1][i-1]);
                if(grid[j][i]>grid[j][i-1]) mat[j][i]=max(mat[j][i],1+mat[j][i-1]);
                if(j<rz-1 && grid[j][i]>grid[j+1][i-1]) mat[j][i]=max(mat[j][i],1+mat[j+1][i-1]);
                r = max(r,mat[j][i]);
            }
            if(r!=i) break;
        }
        return r;
    }
};