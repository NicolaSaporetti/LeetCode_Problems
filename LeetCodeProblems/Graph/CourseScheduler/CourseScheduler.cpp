#include <vector>
#include "KahnAlgorithm.cpp"
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++) graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        Kahn cycleDetection(numCourses);
        return !cycleDetection.find_cycle(graph);
    }
};