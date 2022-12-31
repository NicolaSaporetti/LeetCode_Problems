#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        tot = 0;
        initialize(grid);
        traverseGrid(start);
        return tot;
    }

private:
    void initialize(vector<vector<int>>& grid)
    {
        rz = grid.size();
        cz = grid[0].size();
        dx = {1,-1,0,0};
        dy = {0,0,1,-1};
        visited.assign(rz,vector<bool>(cz,false));
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++)
            {
                if(grid[i][j]==1 || grid[i][j]==-1) visited[i][j]=true;
                if(grid[i][j]==1) start = {i,j};
                if(grid[i][j]==2) end = {i,j};
            }
    }

    void traverseGrid(pair<int,int> start)
    {
        for(int i=0;i<4;i++)
        {
            int nx = start.first+dx[i];
            int ny = start.second+dy[i];
            if(nx<0 || nx>=rz || ny<0 || ny>=cz || visited[nx][ny]) continue;
            visited[nx][ny]=true;
            if(nx==end.first && ny==end.second) verifyIfBoardIsCovered();
            else traverseGrid({nx,ny});
            visited[nx][ny]=false;
        }
    }

    void verifyIfBoardIsCovered()
    {
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) if(visited[i][j]==false) return;
        tot++;
    }

    int rz;
    int cz;
    vector<int> dx;
    vector<int> dy;
    vector<vector<bool>> visited;
    pair<int,int> start;
    pair<int,int> end;
    int tot;
};