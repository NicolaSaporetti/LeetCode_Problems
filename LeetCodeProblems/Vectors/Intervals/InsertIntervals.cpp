#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0]) result.push_back(intervals[i++]);
        if(i>=intervals.size() || intervals[i][0]>newInterval[1]) result.push_back(newInterval);
        else
        {
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            while(i<intervals.size() && intervals[i][0]<=newInterval[1]) newInterval[1] = max(newInterval[1],intervals[i++][1]);
            result.push_back(newInterval);
        }
        while(i<intervals.size()) result.push_back(intervals[i++]);
        return result;
    }
    
    vector<vector<int>> result;
};