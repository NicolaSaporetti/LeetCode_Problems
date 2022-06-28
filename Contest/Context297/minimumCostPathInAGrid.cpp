#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

typedef struct
{
    int weight;
    int i;
    int j;
    bool evaluated;
} Node;

typedef pair<int, Node*> pi;

class Solution {
private:
    int row_sz;
    int col_sz;
    vector<vector<Node>> graph;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    void initializeNodes(vector<vector<int>>& grid)
    {
        graph.resize(row_sz);
        for(int i=0;i<row_sz;i++)
        {
            graph[i].resize(col_sz);
            for(int j=0;j<col_sz;j++)
            {
                graph[i][j].i=i;
                graph[i][j].j=j;
                graph[i][j].weight = INT_MAX;
                graph[i][j].evaluated = false;
            }
        }
        for(int i=0;i<col_sz;i++)
        {
            graph[0][i].weight = grid[0][i];
            pq.push(pair<int,Node*>(grid[0][i],&graph[0][i]));
        }
    }
    
    void updateWeightAndInsertElementInSet(int row, int col, int new_col, vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        if(!graph[row+1][new_col].evaluated)
        {
            graph[row+1][new_col].weight = min(graph[row+1][new_col].weight,(graph[row][col].weight+grid[row+1][new_col]+moveCost[grid[row][col]][new_col]));
            pq.push(pair<int,Node*>(graph[row+1][new_col].weight,&graph[row+1][new_col]));
        }
    }
    
    int computeMinimumObstacles(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        Node* elem = nullptr;
        do
        {
            elem = pq.top().second;
            if(elem->i == row_sz-1) return elem->weight;
            pq.pop();
            if(!elem->evaluated)
            {
                for(int i=0;i<col_sz;i++) updateWeightAndInsertElementInSet(elem->i, elem->j, i, grid, moveCost);
                elem->evaluated = true;
            }
        }
        while(pq.size()>0);
        return 0;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        initializeNodes(grid);
		return computeMinimumObstacles(grid,moveCost);
    }
};