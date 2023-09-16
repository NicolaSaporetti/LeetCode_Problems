#include <vector>
#include <unordered_map>
#include "Kahn"
#include "TopologicalSort"
using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(auto& e : group) if(e==-1) e=m++;
        vector<vector<int>> beforeState(m);
        vector<unordered_map<int,int>> stateToSubstatesubstateToStatePos(m);
        vector<vector<int>> substateToStatePos(m);
        vector<vector<vector<int>>> substateDependencies(m);
        for(int i=0;i<n;i++)
        {
            stateToSubstatesubstateToStatePos[group[i]][i]=stateToSubstatesubstateToStatePos[group[i]].size();
            substateToStatePos[group[i]].push_back(i);
        }
        for(int i=0;i<m;i++) substateDependencies[i].resize(stateToSubstatesubstateToStatePos[i].size());
        for(int i=0;i<n;i++)
            for(auto& dep : beforeItems[i])
            {
                int g = group[i];
                if(group[dep]!=g) beforeState[g].push_back(group[dep]);
                else substateDependencies[g][stateToSubstatesubstateToStatePos[g][i]].push_back(stateToSubstatesubstateToStatePos[g][dep]);
            }
        if(loopDetected(beforeState, substateDependencies)) return {};
        else
        {
            vector<int> res;
            TopologicalSort ts(m);
            vector<int> groupPrio = ts.topological_sort(beforeState);
            for(int i=0;i<m;i++)
            {
                int g = groupPrio[i];
                TopologicalSort ts(substateDependencies[g].size());
                vector<int> sortedEl = ts.topological_sort(substateDependencies[g]);
                for(auto& e : sortedEl) res.push_back(substateToStatePos[g][e]);
            }
            return res;
        }
        return group;
    }
private:
    bool loopDetected(vector<vector<int>>& beforeState, vector<vector<vector<int>>>& substateDependencies)
    {
        Kahn k(beforeState.size());
        if(k.find_cycle(beforeState)) return true;
        else
        {
            for(int i=0;i<beforeState.size();i++)
            {
                Kahn kS(substateDependencies[i].size());
                if(kS.find_cycle(substateDependencies[i])) return true;
            }
        }
        return false;
    }
};