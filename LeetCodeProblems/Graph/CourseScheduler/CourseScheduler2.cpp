#include <vector>
#include "KahnAlgorithm.cpp"
#include "TopologicalSort.cpp"
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++) graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        Kahn cycleDetection(numCourses);
        if(cycleDetection.find_cycle(graph))
        {
            vector<int> result;
            return result;
        }
        else
        {
            TopologicalSort ts(numCourses);
            return ts.topological_sort(graph);
        }
    }
};