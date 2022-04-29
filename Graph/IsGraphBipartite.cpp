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
                            cout<<"set is not empty"<<endl;
                            j=*elementsToEvaluate.begin();
                            elementsToEvaluate.erase(j);
                        }
                        else{
                            cout<<"set is empty"<<endl;
                        }
                        cout<<"Element: "<<j<<endl;
                        elementsEvaluated.insert(j);
                        if(setA.find(j)==setA.end() && setB.find(j)==setB.end())
                        {
                            bool exit=false;
                            for(int i=0;i<graph[j].size() && !exit;i++)
                            {
                                if(setA.find(graph[j][i])!=setA.end()) //is in A
                                {
                                    cout<<"Add in B"<<endl;
                                    setB.insert(j);
                                    exit = true;
                                }
                                if(setB.find(graph[j][i])!=setB.end()) //is in B
                                {
                                    cout<<"Add in A"<<endl;
                                    setA.insert(j);
                                    exit = true;
                                }
                            }
                            if(!exit)
                            {
                                cout<<"Add in A"<<endl;
                                setA.insert(j);
                            }
                        }
                        if(setA.find(j)!=setA.end())
                        {
                            cout<<"Is in A"<<endl;
                            for(int i=0;i<graph[j].size();i++)
                            {
                                if(setA.find(graph[j][i])!=setA.end())
                                {
                                    return false;
                                }
                                else{
                                    if(setB.find(graph[j][i])==setB.end())
                                    {
                                        cout<<"Add: "<<graph[j][i]<<" in B"<<endl;
                                        setB.insert(graph[j][i]);
                                        cout<<"Element: "<<graph[j][i]<<" has to be evaluated"<<endl;
                                        elementsToEvaluate.insert(graph[j][i]);
                                    }
                                }
                            }
                        }
                        else{
                            cout<<"Is in B"<<endl;
                            for(int i=0;i<graph[j].size();i++)
                            {
                                if(setB.find(graph[j][i])!=setB.end())
                                {
                                    return false;
                                }
                                else{
                                    if(setA.find(graph[j][i])==setA.end())
                                    {
                                        cout<<"Add: "<<graph[j][i]<<" in A"<<endl;
                                        setA.insert(graph[j][i]);
                                        cout<<"Element: "<<graph[j][i]<<" has to be evaluated"<<endl;
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

int main()
{
    Solution sol;
    //vector<vector<int>> graph = {{1},{0,3},{3},{1,2}};
    //vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    //vector<vector<int>> graph = {{3},{2,4},{1},{0,4},{1,3}};
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    cout<<sol.isBipartite(graph)<<endl;
}