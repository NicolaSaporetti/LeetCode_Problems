#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int x;
    int y;
} Cell;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> sol;
        row_sz = heights.size();
        col_sz = heights[0].size();
        vector<vector<bool>> atl(row_sz,vector<bool>(col_sz,false));
        vector<vector<bool>> pac(row_sz,vector<bool>(col_sz,false));
        
        setUpAtlantic(heights,atl);
        setUpPacific(heights,pac);
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(atl[i][j] && pac[i][j])
                {
                    vector<int> temp = {i,j};
                    sol.push_back(temp);
                }
            }
        }
        return sol;
    }
private:
    void setUpAtlantic(vector<vector<int>>& heights, vector<vector<bool>>& atl)
    {
        Cell cell;
        cell.y =col_sz-1;
        for(int i=0;i<row_sz;i++)
        {
            cell.x =i;
            myQ.push(cell);
        }
        cell.x =row_sz-1;
        for(int j=0;j<col_sz;j++)
        {
            cell.y =j;
            myQ.push(cell);
        }
        while(!myQ.empty())
        {
            Cell cell = myQ.front();
            myQ.pop();
            if(atl[cell.x][cell.y] == 0) computeWaterAtlFlowNeighburingCell(heights, cell, atl);
        }
    }
    
    void setUpPacific(vector<vector<int>>& heights, vector<vector<bool>>& pac)
    {
        Cell cell;
        cell.y =0;
        for(int i=0;i<row_sz;i++)
        {
            cell.x =i;
            myQ.push(cell);
        }
        cell.x =0;
        for(int j=0;j<col_sz;j++)
        {
            cell.y =j;
            myQ.push(cell);
        }
        while(!myQ.empty())
        {
            Cell cell = myQ.front();
            myQ.pop();
            if(pac[cell.x][cell.y] == 0) computeWaterAtlFlowNeighburingCell(heights, cell, pac);
        }
    }
    
    void computeWaterAtlFlowNeighburingCell(vector<vector<int>>& heights, Cell cell, vector<vector<bool>>& ocean)
    {
        Cell temp;
        ocean[cell.x][cell.y]=true;
        if(cell.x+1<row_sz && heights[cell.x+1][cell.y]>=heights[cell.x][cell.y])
        {
            temp.x = cell.x+1;
            temp.y = cell.y;
            myQ.push(temp);
        }
        if(cell.x-1>=0 && heights[cell.x-1][cell.y]>=heights[cell.x][cell.y])
        {
            temp.x = cell.x-1;
            temp.y = cell.y;
            myQ.push(temp);
        }
        if(cell.y+1<col_sz && heights[cell.x][cell.y+1]>=heights[cell.x][cell.y])
        {
            temp.x = cell.x;
            temp.y = cell.y+1;
            myQ.push(temp);
        }
        if(cell.y-1>=0 && heights[cell.x][cell.y-1]>=heights[cell.x][cell.y])
        {
            temp.x = cell.x;
            temp.y = cell.y-1;
            myQ.push(temp);
        }
    }
    
    queue<Cell> myQ;
    int row_sz;
    int col_sz;
};