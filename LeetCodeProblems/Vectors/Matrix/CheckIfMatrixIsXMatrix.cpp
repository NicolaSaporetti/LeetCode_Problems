#include <vector>
using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int sz = grid.size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(i==j || i==sz-1-j)
                {
                    if(grid[i][j]==0) return false;
                }
                else if(grid[i][j]!=0) return false;
            }
        }
        return true;
    }
};