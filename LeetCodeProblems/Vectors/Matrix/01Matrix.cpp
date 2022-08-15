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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row_sz = mat.size();
        int col_sz = mat[0].size();
        cell newC = {0,0,0};
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(mat[i][j]==0)
                {
                    newC.weight = 0;
                    newC.row = i;
                    newC.col = j;
                    pq.push(newC);
                }
                mat[i][j]=-1;
            }
        }
        while(!pq.empty())
        {
            cell cur = pq.top();
            pq.pop();
            if(mat[cur.row][cur.col]==-1)
            {
                mat[cur.row][cur.col] = cur.weight;
                cur.weight++;
                if(cur.row+1<row_sz)
                {
                    cur.row++;
                    pq.push(cur);
                    cur.row--;
                }
                if(cur.col+1<col_sz)
                {
                    cur.col++;
                    pq.push(cur);
                    cur.col--;
                }
                if(cur.row-1>=0)
                {
                    cur.row--;
                    pq.push(cur);
                    cur.row++;
                }
                if(cur.col-1>=0)
                {
                    cur.col--;
                    pq.push(cur);
                    cur.col++;
                }
            }
        }
        return mat;
    }
};