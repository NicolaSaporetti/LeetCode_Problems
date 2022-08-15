#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

typedef struct
{
    int i;
    int j;
} Node;

struct myComp {
  bool operator() (pair<int, Node> const& top_pq,
                   pair<int, Node> const& new_el)
  { return top_pq.first > new_el.first;}
};

typedef pair<int, Node> pi;

class Solution {
private:
    int row_sz;
    int col_sz;
    priority_queue<pi, vector<pi>, myComp> pq;
    
    void updateWeightAndInsertElementInSet(int row, int col, int weight, vector<vector<int>>& grid)
    {
        Node node = {row,col};
        if(grid[row][col]==-1)
        {
            pq.push(make_pair(weight,node));
        }
    }
    
    int computeDepth(vector<vector<int>>& grid) {
        int valid_weight = -1;
        while(!pq.empty())
        {
            Node elem = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(grid[elem.i][elem.j]==-1)
            {
                valid_weight = weight;
                grid[elem.i][elem.j]=weight;
                if(elem.i+1<row_sz) updateWeightAndInsertElementInSet(elem.i+1,elem.j,  weight+1, grid);
                if(elem.i-1>=0)     updateWeightAndInsertElementInSet(elem.i-1,elem.j,  weight+1, grid);
                if(elem.j+1<col_sz) updateWeightAndInsertElementInSet(elem.i,  elem.j+1,weight+1, grid);
                if(elem.j-1>=0)     updateWeightAndInsertElementInSet(elem.i,  elem.j-1,weight+1, grid);
            }
        }
        return valid_weight;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        Node node = {0,0};
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(grid[i][j]==1)
                {
                    node.i = i;
                    node.j = j;
                    pq.push(make_pair(0,node));
                }
                grid[i][j]=-1;
            }
        }
		int value = computeDepth(grid);
        if(value==0) return -1;
        else return value;
    }
};