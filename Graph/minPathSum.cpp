#include <iostream>
#include <stdlib.h>
#include <unordered_set>
#include <vector>

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
    int m;
    int n;
    vector<vector<Node>> weight;
    unordered_set<Node*> elementsToEvaluate;
    void initializeNodes(int firstWeight)
    {
        Node node;
        weight.resize(m);
        for(int i=0;i<m;i++)
        {
            weight[i].resize(n);
            for(int j=0;j<n;j++)
            {
                node.i=i;
                node.j=j;
                node.weight=10000;
                weight[i][j]= node;
            }
        }
        weight[0][0].weight=firstWeight;
        elementsToEvaluate.insert(&weight[0][0]);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int length = 0;
        initializeNodes(grid[0][0]);
        do
        {
            unordered_set<Node*>::iterator current;
            Node* temp =nullptr;
            int tempweight = 10000;
            for(auto it=elementsToEvaluate.begin();it!=elementsToEvaluate.end();it++)
            {
                //cout<<"Element i("<<(*it)->i<<"), j("<<(*it)->j<<"). Weight: "<<(*it)->weight<<endl;
                if((*it)->weight<tempweight)
                {
                    tempweight = (*it)->weight;
                    current = it;
                }
            }
            temp = *current;
            elementsToEvaluate.erase(current);
            temp->evaluated = true;
            int i=temp->i;
            int j=temp->j;
            if(i==m-1 && j==n-1)
            {
                length =temp->weight;
                break;
            }
            if(i+1<m && !weight[i+1][j].evaluated)
            {
                //cout<<"i: "<<i+1<<",j: "<<j<<endl;
                int newWeight=temp->weight+grid[i+1][j];
                if(newWeight<weight[i+1][j].weight)
                {
                    weight[i+1][j].weight=newWeight;
                    //cout<<"Update weight: "<<weight[i+1][j].weight<<endl;
                }
                elementsToEvaluate.insert(&weight[i+1][j]);
            }
            if(j+1<n && !weight[i][j+1].evaluated)
            {
                //cout<<"i: "<<i<<",j: "<<j+1<<endl;
                int newWeight=temp->weight+grid[i][j+1];
                if(newWeight<weight[i][j+1].weight)
                {
                    weight[i][j+1].weight=newWeight;
                    //cout<<"Update weight: "<<weight[i][j+1].weight<<endl;
                }
                elementsToEvaluate.insert(&weight[i][j+1]);
            }
        }
        while(elementsToEvaluate.size()>0);
        return length;
    }
};

int main()
{
    Solution solution;
    return 0;
}