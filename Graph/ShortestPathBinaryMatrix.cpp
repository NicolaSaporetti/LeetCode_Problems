#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

typedef struct
{
    int i;
    int j;
    int weight;
    bool evaluated;
} Node;

typedef pair<int, Node*> pi;

struct myComp {
  bool operator() (pair<int, Node*> const& a,
                   pair<int, Node*> const& b)
  { return a.first > b.first;}
};

class Solution {
private:
    int sz;
    vector<vector<Node>> graph;
    priority_queue<pi, vector<pi>, myComp> pQ;
    void initializeNodes()
    {
        Node node;
        node.evaluated = false;
        node.weight = 10000;
        graph.resize(sz);
        for(int i=0;i<sz;i++)
        {
            graph[i].resize(sz);
            for(int j=0;j<sz;j++)
            {
                node.i=i;
                node.j=j;
                graph[i][j]= node;
            }
        }
        graph[0][0].weight = 1;
        pQ.push(make_pair(1,&graph[0][0]));
    }
    
    int computeshortestPathBinaryMatrix(vector<vector<int>>& grid) {
        Node* elem = nullptr;
        int current_weight = 0;
        do
        {
            elem = pQ.top().second;
            current_weight = elem->weight;
            pQ.pop();
            if(!elem->evaluated)
            {
                if(elem->i == sz-1 && elem->j==sz-1) return current_weight;
                for(int i=1;i>-2;i--)
                {
                    for(int j=1;j>-2;j--)
                    {
                        int newRow = elem->i+i;
                        int newCol = elem->j+j;
                        if(newRow<sz && newRow>=0 && newCol<sz && newCol>=0 &&
                           !grid[newRow][newCol] && !graph[newRow][newCol].evaluated)
                        {
                            if(graph[newRow][newCol].weight>current_weight+1)
                            {
                                graph[newRow][newCol].weight=current_weight+1;
                                pQ.push(make_pair(current_weight+1, &graph[newRow][newCol]));
                            }
                        }
                    }
                }
                elem->evaluated = true;
            }
        }
        while(pQ.size()>0);
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        sz = grid.size();
        if(grid[0][0] || grid[sz-1][sz-1]) return -1;
        initializeNodes();
		return computeshortestPathBinaryMatrix(grid);
    }
};