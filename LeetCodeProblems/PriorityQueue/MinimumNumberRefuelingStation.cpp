#include <priority_queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int pos = 0;
        int result = 0;
        while(startFuel<target)
        {
            while(pos<stations.size() && stations[pos][0]<=startFuel) pq.push(stations[pos++][1]);
            if(pq.empty()) return -1;
            else
            {
                startFuel+=pq.top();
                pq.pop();
                result++;
            }
        }
        return result;
    }
};