#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

typedef struct
{
    int weight;
    bool evaluated;
} Node;

typedef struct
{
    int destination;
    int connectionWeight;
} Edge;

class Solution {
private:
    int sz;
    int evaluated_elements;
    vector<Node> updatedWeights;
    vector<vector<Edge>> graph;
    unordered_set<int> elementsToEvaluate;
    void initializeWeights(vector<vector<int>>& times, int k) {
        Node node;
        evaluated_elements = 0;
        updatedWeights.resize(sz+1);
        for(int i=0;i<sz+1;i++)
        {
            node.weight = 10000000;
            updatedWeights[i] = node;
        }
        updatedWeights[k].weight=0;
    }
        
    void initializeEdges(vector<vector<int>>& times, int k) {
        Edge newEdge;
        graph.resize(sz+1);
        for(int i =0; i<times.size(); i++)
        {
            newEdge.destination = times[i][1];
            newEdge.connectionWeight = times[i][2];
            graph[times[i][0]].push_back(newEdge);
        }
        elementsToEvaluate.insert(k);
    }
    
    int findElementToEvaluate() {
        int chosenNode = -1;
        unordered_set<int>::iterator current;
        int tempweight = 1000000;
        for(auto it=elementsToEvaluate.begin();it!=elementsToEvaluate.end();it++)
        {
            if(updatedWeights[(*it)].weight<tempweight)
            {
                tempweight = updatedWeights[(*it)].weight;
                current = it;
            }
        }
        chosenNode = *current;
        elementsToEvaluate.erase(current);
        return chosenNode;
    }
    
    int computeNetworkDelay() {
        int elem = -1;
        int current_weight = 0;
        do
        {
            elem = findElementToEvaluate();
            current_weight = updatedWeights[elem].weight;
            for(int i=0;i<graph[elem].size();i++)
            {
                int destination = graph[elem][i].destination;
                int edgeWeight = graph[elem][i].connectionWeight;
                if(!updatedWeights[destination].evaluated && updatedWeights[destination].weight>updatedWeights[elem].weight+edgeWeight)
                {
                    updatedWeights[destination].weight=updatedWeights[elem].weight+edgeWeight;
                    elementsToEvaluate.insert(destination);
                }
            }
            updatedWeights[elem].evaluated = true;
            evaluated_elements++;
        }
        while(elementsToEvaluate.size()>0);
        return current_weight;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        sz = n;
        initializeWeights(times, k);
        initializeEdges(times, k);
        int totalDelay = computeNetworkDelay();
        if(evaluated_elements<sz) return -1;
        else return totalDelay;
    }
};