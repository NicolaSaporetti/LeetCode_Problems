#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

typedef struct
{
    int weight;
    int i;
    int j;
} Node;

class Solution {
private:
    int row_sz;
    int col_sz;
    vector<vector<Node>> graph;
    unordered_set<Node*> elementsToEvaluate;
    int maxLenght;
    
    void initializeNodes()
    {
        Node node;
        graph.resize(row_sz);
        for(int i=0;i<row_sz;i++)
        {
            graph[i].resize(col_sz);
            for(int j=0;j<col_sz;j++)
            {
                node.i=i;
                node.j=j;
                graph[i][j]= node;
            }
        }
    }
    
    int findMax(vector<vector<int>>& matrix)
    {
        int maxE = 0;
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                maxE = max(maxE, matrix[i][j]);
            }
        }
        return maxE;
    }
    
    void reset(int start_row, int start_col)
    {
        elementsToEvaluate.clear();
        
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                graph[i][j].weight = -1;
            }
        }
        graph[start_row][start_col].weight=1;
        elementsToEvaluate.insert(&graph[start_row][start_col]);
    }
	
    Node* findElementToEvaluate(vector<vector<int>>& matrix) {
        Node* chosenNode = nullptr;
        unordered_set<Node*>::iterator current;
        int tempweight = 2147483647;
        for(auto it=elementsToEvaluate.begin();it!=elementsToEvaluate.end();it++)
        {
            if(matrix[(*it)->i][(*it)->j]<=tempweight)
            {
                tempweight = graph[(*it)->i][(*it)->j].weight;
                current = it;
            }
        }
        chosenNode = *current;
        elementsToEvaluate.erase(current);
        return chosenNode;
    }
    
    void updateWeight(int current_weight, int newRow, int newCol)
    {
        if(graph[newRow][newCol].weight<current_weight+1)
        {
            graph[newRow][newCol].weight=current_weight+1;
            elementsToEvaluate.insert(&graph[newRow][newCol]);
        }
    }
    
    void computelongestIncreasingPath(vector<vector<int>>& matrix) {
        Node* elem = nullptr;
        int current_weight = 0;
        do
        {
            elem = findElementToEvaluate(matrix);
            current_weight = elem->weight;
            if(maxLenght<current_weight) maxLenght = current_weight;
			if(elem->i+1<row_sz && matrix[elem->i+1][elem->j]>matrix[elem->i][elem->j])
            {
                updateWeight(current_weight, elem->i+1, elem->j);
            }
            if(elem->i-1>=0 && matrix[elem->i-1][elem->j]>matrix[elem->i][elem->j])
            {
                updateWeight(current_weight, elem->i-1, elem->j);
            }
            if(elem->j+1<col_sz && matrix[elem->i][elem->j+1]>matrix[elem->i][elem->j])
            {
                updateWeight(current_weight, elem->i, elem->j+1);
            }
            if(elem->j-1>=0 && matrix[elem->i][elem->j-1]>matrix[elem->i][elem->j])
            {
                updateWeight(current_weight, elem->i, elem->j-1);
            }
        }
        while(elementsToEvaluate.size()>0);
    }
    
    bool bestNumberInNeighboourd(vector<vector<int>>& matrix, int row, int col)
    {
        if(row+1<row_sz && matrix[row][col]>matrix[row+1][col]) return false;
        if(row-1>=0 && matrix[row][col]>matrix[row-1][col]) return false;
        if(col+1<col_sz && matrix[row][col]>matrix[row][col+1]) return false;
        if(col-1>=0 && matrix[row][col]>matrix[row][col-1]) return false;
        return true;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row_sz = matrix.size();
        col_sz = matrix[0].size();
        initializeNodes();
        int max = findMax(matrix);
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(max-maxLenght>=matrix[i][j] && bestNumberInNeighboourd(matrix, i, j))
                {
                    reset(i,j);
		            computelongestIncreasingPath(matrix);
                }
            }
        }
        return maxLenght;
    }
};