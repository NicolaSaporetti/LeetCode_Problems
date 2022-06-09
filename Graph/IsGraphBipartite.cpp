#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    int sz;
    unordered_set<int> setA;
    unordered_set<int> setB;
    unordered_set<int> elementsEvaluated;
    unordered_set<int> elementsToEvaluate;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        sz=graph.size();
        if(sz<2) return false;
        else {
            for(int j=0;j<sz;j++)
            {
                if(elementsEvaluated.find(j)==elementsEvaluated.end())
                {
                    do
                    {
                        if(!elementsToEvaluate.empty())
                        {
                            j=*elementsToEvaluate.begin();
                            elementsToEvaluate.erase(j);
                        }
                        elementsEvaluated.insert(j);
                        if(setA.find(j)==setA.end() && setB.find(j)==setB.end())
                        {
                            bool exit=false;
                            for(int i=0;i<graph[j].size() && !exit;i++)
                            {
                                if(setA.find(graph[j][i])!=setA.end()) //is in A
                                {
                                    setB.insert(j);
                                    exit = true;
                                }
                                if(setB.find(graph[j][i])!=setB.end()) //is in B
                                {
                                    setA.insert(j);
                                    exit = true;
                                }
                            }
                            if(!exit)
                            {
                                setA.insert(j);
                            }
                        }
                        if(setA.find(j)!=setA.end())
                        {
                            for(int i=0;i<graph[j].size();i++)
                            {
                                if(setA.find(graph[j][i])!=setA.end())
                                {
                                    return false;
                                }
                                else{
                                    if(setB.find(graph[j][i])==setB.end())
                                    {
                                        setB.insert(graph[j][i]);
                                        elementsToEvaluate.insert(graph[j][i]);
                                    }
                                }
                            }
                        }
                        else{
                            for(int i=0;i<graph[j].size();i++)
                            {
                                if(setB.find(graph[j][i])!=setB.end())
                                {
                                    return false;
                                }
                                else{
                                    if(setA.find(graph[j][i])==setA.end())
                                    {
                                        setA.insert(graph[j][i]);
                                        elementsToEvaluate.insert(graph[j][i]);
                                    }
                                }
                            }
                        }
                    } while (!elementsToEvaluate.empty());
                }
            }       
        }
        return true;
    }
};