#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int rz=grid.size();
        int cz=grid[0].size();
        int val = 0;
        for(int i=0;i<=rz-3;i++)
        {
            for(int j=0;j<=cz-3;j++)
            {
                val = max(val,computeH(i,j,grid););
            }
        }
        return val;
    }
private:
    int computeH(int sr, int sc, vector<vector<int>>& grid)
    {   
        int temp = 0;
        for(int r=0;r<3;r++)
            temp+=grid[sr][sc+r];
        temp+=grid[sr+1][sc+1];
        for(int r=0;r<3;r++)
            temp+=grid[sr+2][sc+r];
        return temp;
    }
};