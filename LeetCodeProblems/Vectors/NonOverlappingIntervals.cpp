#include <iostream>
#include <vector>
using namespace std;

bool mySort (vector<int>& i,vector<int>& j) {
    return (i[0]<j[0] || (i[0]==j[0] && i[1]<j[1])); 
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int erase = 0;
        sort(intervals.begin(),intervals.end(),mySort);
        int high = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<high && intervals[i][1]>=high)
            {
                erase++;
            }
            else if(intervals[i][1] < high)
            {
                erase++;
                high = intervals[i][1];
            }
            else
            {
                high = intervals[i][1];
            }
        }
        return erase;
    }
};