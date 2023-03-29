#include <vector>
using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        int x = 0;
        int y = 0;
        int cur = 0;
        int rz = grid.size();
        int cz = grid[0].size();
        int maxC = rz*cz;
        vector<int> dx = {-2,-1,1,2,2,1,-1,-2};
        vector<int> dy = {1,2,2,1,-1,-2,-2,-1};
        while(cur<maxC-1)
        {
            bool newValidCell = false;
            for(int i=0;i<8;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || nx>=rz || ny<0 || ny>=cz || grid[nx][ny]!=cur+1) continue;
                newValidCell = true;
                x = nx;
                y = ny;
                break;
            }
            if(!newValidCell) return false;
            cur++;
        }
        return true;
    }
};