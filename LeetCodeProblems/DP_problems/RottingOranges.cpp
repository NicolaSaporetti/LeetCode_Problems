#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

typedef struct
{
    int weight;
    int row;
    int col;
} cell;

struct myComp { 
    bool operator()(cell const& a, cell const& b)
    {
        return a.weight>b.weight;
    }
};

class Solution {
private:
    priority_queue<cell, vector<cell>, myComp> pq;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row_sz = grid.size();
        int col_sz = grid[0].size();
        cell newC = {0,0,0};
        int res = 0;
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]==2)
                {
                    newC.weight = 0;
                    newC.row = i;
                    newC.col = j;
                    pq.push(newC);
                }
            }
        }
        while(!pq.empty())
        {
            cell cur = pq.top();
            pq.pop();
            res = cur.weight;
            cur.weight++;
            if(cur.row+1<row_sz && grid[cur.row+1][cur.col]==1)
            {
                cur.row++;
                grid[cur.row][cur.col]=2;
                pq.push(cur);
                cur.row--;
            }
            if(cur.col+1<col_sz && grid[cur.row][cur.col+1]==1)
            {
                cur.col++;
                grid[cur.row][cur.col]=2;
                pq.push(cur);
                cur.col--;
            }
            if(cur.row-1>=0 && grid[cur.row-1][cur.col]==1)
            {
                cur.row--;
                grid[cur.row][cur.col]=2;
                pq.push(cur);
                cur.row++;
            }
            if(cur.col-1>=0 && grid[cur.row][cur.col-1]==1)
            {
                cur.col--;
                grid[cur.row][cur.col]=2;
                pq.push(cur);
                cur.col++;
            }
        }
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return res;
    }
};