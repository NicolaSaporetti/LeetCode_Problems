#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        sz=graph.size();
        elementsEvaluated.resize(sz);
        unordered_set<int> setA;
        unordered_set<int> setB;
        
        for(int i=0;i<sz;i++) elementsEvaluated[i]=false;
        for(int i=0;i<sz;i++)
        {
            if(!elementsEvaluated[i] && graph[i].size()>0)
            {
                setA.insert(i);
                elementsToEvaluate.push(i);
                elementsEvaluated[i]=true;
                if(!evaluate(graph, setA, setB)) return false;
            }
        }       
        if((!setA.empty() && setB.empty()) || (setA.empty() && !setB.empty())) return false;
        return true;
    }
private:
    
    bool evaluate(vector<vector<int>>& graph, unordered_set<int>& firstPartition, unordered_set<int>& secondPartition)
    {
        int n = elementsToEvaluate.size();
        int elem = 0;
        for(int i=0;i<n;i++)
        {
            if(!putElementInSet(graph,firstPartition,secondPartition)) return false;
        }
        if(!elementsToEvaluate.empty()) return evaluate(graph,secondPartition,firstPartition);
        else return true;
    }
    
    bool putElementInSet(vector<vector<int>>& graph, unordered_set<int>& firstPartition, unordered_set<int>& secondPartition)
    {
        int elem = elementsToEvaluate.front();
        elementsToEvaluate.pop();
        for(int j=0;j<graph[elem].size();j++)
        {
            int newElem = graph[elem][j];
            if(firstPartition.find(newElem)!=firstPartition.end()) return false;
            else if(!elementsEvaluated[newElem])
            {
                secondPartition.insert(newElem);
                elementsToEvaluate.push(newElem);
                elementsEvaluated[newElem]=true;
            }
        }
        return true;
    }
    
    int sz;
    queue<int> elementsToEvaluate;
    vector<bool> elementsEvaluated;
};