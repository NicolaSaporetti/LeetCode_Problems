#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

typedef struct Node
{
    int i;
    int j;
} Node;

typedef pair<int, Node> pi;

struct myComp {
    constexpr bool operator()(
        pair<int, Node> const& a,
        pair<int, Node> const& b)
    {
        return a.first < b.first;
    }
};

class Solution {
private:
    int row_sz;
    int col_sz;
    priority_queue<pi, vector<pi>, myComp> pq;
    void initializeNodes(vector<vector<char>>& grid)
    {
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]=='1')
                {
                    Node node = {i,j};
                    pq.push(make_pair(0,node));
                }
            }
        }
    }
    
    void updatePQ(int row, int col, vector<vector<char>>& grid)
    {
        if(grid[row][col]=='1')
        {
            Node node = {row,col};
            pq.push(make_pair(1, node));
        }
    }
    
    int computeNumIslands(vector<vector<char>>& grid) {
        int islandsNumber = 0;
        int priority = -1;
        Node node;
        while(pq.size()>0)
        {
            node = pq.top().second;
            priority = pq.top().first;
            pq.pop();
            if(grid[node.i][node.j]!='0')
            {
                if(node.i+1<row_sz) updatePQ(node.i+1,node.j,   grid);
                if(node.i-1>=0)     updatePQ(node.i-1,node.j,   grid);
                if(node.j+1<col_sz) updatePQ(node.i,  node.j+1, grid);
                if(node.j-1>=0)     updatePQ(node.i,  node.j-1, grid);
                if(grid[node.i][node.j]== '1' && !priority)
                {
                    islandsNumber++;
                }
                grid[node.i][node.j]='0';
            }
        }
        return islandsNumber;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        initializeNodes(grid);
		return computeNumIslands(grid);
    }
};