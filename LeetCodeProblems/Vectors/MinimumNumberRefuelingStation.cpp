#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int station_index = 0;
        int number_refueling = 0;
        while(startFuel<target)
        {
            while(station_index<stations.size() && stations[station_index][0]<=startFuel)
            {
                pq.push(stations[station_index][1]);
                station_index++;
            }
            if(pq.empty()) return -1;
            else 
            {
                startFuel+=pq.top();
                number_refueling++;
                pq.pop();
            }
        }
        return number_refueling;
    }
};