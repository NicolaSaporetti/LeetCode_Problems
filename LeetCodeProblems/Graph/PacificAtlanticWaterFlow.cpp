#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> sol;
        row_sz = heights.size();
        col_sz = heights[0].size();
        vector<vector<bool>> atl(row_sz,vector<bool>(col_sz,false));
        vector<vector<bool>> pac(row_sz,vector<bool>(col_sz,false));
        dx={1,-1,0,0};
        dy={0,0,1,-1};
        
        setUpAtlantic(heights,atl);
        setUpPacific(heights,pac);
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(atl[i][j] && pac[i][j]) sol.push_back({i,j});
            }
        }
        return sol;
    }
private:
    void setUpAtlantic(vector<vector<int>>& heights, vector<vector<bool>>& ocean)
    {
        for(int i=0;i<row_sz;i++)
        {
            myQ.push({i,col_sz-1});
            ocean[i][col_sz-1]=true;
        }
        for(int i=0;i<col_sz-1;i++)
        {
            myQ.push({row_sz-1,i});
            ocean[row_sz-1][i]=true;
        }
        computeFlow(heights,ocean);
    }
    
    void setUpPacific(vector<vector<int>>& heights, vector<vector<bool>>& ocean)
    {
        for(int i=0;i<row_sz;i++)
        {
            myQ.push({i,0});
            ocean[i][0]=true;
        }
        for(int i=1;i<col_sz;i++)
        {
            myQ.push({0,i});
            ocean[0][i]=true;
        }
        computeFlow(heights,ocean);
    }

    void computeFlow(vector<vector<int>>& heights, vector<vector<bool>>& ocean)
    {
        while(!myQ.empty())
        {
            auto cell = myQ.front();
            myQ.pop();
            for(int i=0;i<4;i++)
            {
                int nx = cell.first+dx[i];
                int ny = cell.second+dy[i];
                if(nx<0 || nx>=row_sz || ny<0 || ny>=col_sz || ocean[nx][ny] || heights[nx][ny]<heights[cell.first][cell.second]) continue;
                myQ.push({nx,ny});
                ocean[nx][ny]=true;
            }
        }
    }
    
    queue<pair<int,int>> myQ;
    vector<int> dx;
    vector<int> dy;
    int row_sz;
    int col_sz;
};