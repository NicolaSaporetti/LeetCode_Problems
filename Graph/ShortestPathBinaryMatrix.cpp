#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

typedef struct
{
    int weight;
    int i;
    int j;
    bool evaluated;
} Node;

class Solution {
private:
    int row_sz;
    int col_sz;
    vector<vector<Node>> graph;
    unordered_set<Node*> elementsToEvaluate;
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
                node.weight=10000;
                graph[i][j]= node;
            }
        }
        graph[0][0].weight=1;
        elementsToEvaluate.insert(&graph[0][0]);
    }
	
    Node* findElementToEvaluate() {
        Node* chosenNode = nullptr;
        unordered_set<Node*>::iterator current;
        int tempweight = 1000000;
        for(auto it=elementsToEvaluate.begin();it!=elementsToEvaluate.end();it++)
        {
			//cout<<"Node i: "<<(*it)->i<<", j: "<<(*it)->j<<", Weight: "<<(*it)->weight<<endl;
            if(graph[(*it)->i][(*it)->j].weight<tempweight)
            {
                tempweight = graph[(*it)->i][(*it)->j].weight;
                current = it;
            }
        }
        chosenNode = *current;
		//cout<<"Selected Node i: "<<chosenNode->i<<", j: "<<chosenNode->j<<", Weight: "<<chosenNode->weight<<endl;
        elementsToEvaluate.erase(current);
        return chosenNode;
    }
    
    int computeshortestPathBinaryMatrix(vector<vector<int>>& grid) {
        Node* elem = nullptr;
        int current_weight = 0;
        do
        {
            elem = findElementToEvaluate();
            current_weight = elem->weight;
			if(elem->i == row_sz-1 && elem->j==col_sz-1) return current_weight;
			else
			{
                for(int i=1;i>-2;i--)
                {
                    //cout<<"I: "<<i<<endl;
                    for(int j=1;j>-2;j--)
                    {
                        //cout<<"J: "<<j<<endl;
                        int newRow = elem->i+i;
                        int newCol = elem->j+j;
                        if(newRow<row_sz && newRow>=0 && newCol<col_sz && newCol>=0 &&
                           !grid[newRow][newCol] && !graph[newRow][newCol].evaluated && !(i==0 && j==0))
                        {
							//cout<<"This node is valid i: "<<newRow<<", j: "<<newCol<<endl;
                            if(graph[newRow][newCol].weight>current_weight+1)
                            {
								//cout<<"Weight updated: "<<current_weight+1<<endl;
                                graph[newRow][newCol].weight=current_weight+1;
                                elementsToEvaluate.insert(&graph[newRow][newCol]);
                            }
                        }
                    }
                }
                elem->evaluated = true;
            }
        }
        while(elementsToEvaluate.size()>0);
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        row_sz = grid.size();
        col_sz = grid[0].size();
        if(grid[0][0] || grid[row_sz-1][col_sz-1]) return -1;
        initializeNodes();
		return computeshortestPathBinaryMatrix(grid);
    }
};

int main()
{
    Solution sol;
    return 0;
}