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
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    void initializeNodes(int startingNodeWeight)
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
        graph[0][0].weight=startingNodeWeight;
        pq.push(pair<int,Node*>(startingNodeWeight,&graph[0][0]));
    }
    
    void updateWeightAndInsertElementInSet(int row, int col, int current_weight, vector<vector<int>>& grid)
    {
        if(!graph[row][col].evaluated)
        {
            graph[row][col].weight = min(graph[row][col].weight,current_weight+grid[row][col]);
            pq.push(pair<int,Node*>(graph[row][col].weight,&graph[row][col]));
        }
    }
    
    int computeMinimumObstacles(vector<vector<int>>& grid) {
        Node* elem = nullptr;
        int current_weight = 0;
        do
        {
            elem = pq.top().second;
            pq.pop();
            if(!elem->evaluated)
            {
                current_weight = elem->weight;
                if(elem->i+1<row_sz) updateWeightAndInsertElementInSet(elem->i+1,elem->j,  current_weight, grid);
                if(elem->i-1>=0)     updateWeightAndInsertElementInSet(elem->i-1,elem->j,  current_weight, grid);
                if(elem->j+1<col_sz) updateWeightAndInsertElementInSet(elem->i,  elem->j+1,current_weight, grid);
                if(elem->j-1>=0)     updateWeightAndInsertElementInSet(elem->i,  elem->j-1,current_weight, grid);
                elem->evaluated = true;
            }
        }
        while(pq.size()>0 && !graph[row_sz-1][col_sz-1].evaluated);
        return current_weight;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        initializeNodes(grid[0][0]);
		return computeMinimumObstacles(grid);
    }
};