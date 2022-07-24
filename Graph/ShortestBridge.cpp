#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

typedef struct
{
    int r;
    int c;
} Node;

struct myComp {
  bool operator() (pair<int, Node> const& top_pq,
                   pair<int, Node> const& new_el)
  { return top_pq.first > new_el.first;}
};

typedef pair<int, Node> pi;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        Node elementIsland = getElementIsland(grid);
        selectIslandArea(elementIsland.r, elementIsland.c, grid);
        setDest(grid);
        
		return computeDepth(grid);
    }
private:
    Node getElementIsland(vector<vector<int>>& grid)
    {
        Node node = {0,0};
        bool islandFound = false;
        for(int i=0;i<row_sz && !islandFound;i++)
        {
            for(int j=0;j<col_sz && !islandFound;j++)
            {
                if(grid[i][j]==1)
                {
                    node.r = i;
                    node.c = j;
                    islandFound = true;
                }
            }
        }
        return node;
    }
    
    void setDest(vector<vector<int>>& grid)
    {
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]==1) grid[i][j] = -2;
            }
        }
    }

    void selectIslandArea(int row, int col, vector<vector<int>>& grid)
    {
        if(row<row_sz && row>=0 && col<col_sz && col>=0)
        {
            if(grid[row][col]==1)
            {
                grid[row][col]=-1;
                Node node = {row, col};
                pq.push(make_pair(1,node));
                selectIslandArea(row+1,col,grid);
                selectIslandArea(row-1,col,grid);
                selectIslandArea(row,col+1,grid);
                selectIslandArea(row,col-1,grid);
            }
            else
            {
                Node node = {row, col};
                pq.push(make_pair(1,node));
            }
        }
    }
    
    int computeDepth(vector<vector<int>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        int valid_weight = 0;
        while(!pq.empty())
        {
            Node elem = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(grid[elem.r][elem.c]==0)
            {
                bool landFound = false;
                valid_weight = weight;
                grid[elem.r][elem.c]=weight;
                if(elem.r+1<row_sz) landFound |= updateWeightAndInsertElementInSet(elem.r+1,elem.c,  weight+1, grid);
                if(elem.r-1>=0)     landFound |= updateWeightAndInsertElementInSet(elem.r-1,elem.c,  weight+1, grid);
                if(elem.c+1<col_sz) landFound |= updateWeightAndInsertElementInSet(elem.r,  elem.c+1,weight+1, grid);
                if(elem.c-1>=0)     landFound |= updateWeightAndInsertElementInSet(elem.r,  elem.c-1,weight+1, grid);
                if(landFound) return valid_weight;
            }
        }
        return valid_weight;
    }
    
    bool updateWeightAndInsertElementInSet(int row, int col, int weight, vector<vector<int>>& grid)
    {
        bool landFound = false;
        Node node = {row,col};
        if(grid[row][col]==0)
        {
            pq.push(make_pair(weight,node));
        }
        if(grid[row][col]==-2) landFound = true;
        return landFound;
    }
    
    void printMax(vector<vector<int>>& grid)
    {
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    int row_sz;
    int col_sz;
    priority_queue<pi, vector<pi>, myComp> pq;
};