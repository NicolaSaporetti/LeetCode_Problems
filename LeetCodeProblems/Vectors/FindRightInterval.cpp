#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> myM;
        vector<int> result;
        int sz = intervals.size();
        for(int i=0;i<sz;i++)
        {
            myM.insert(make_pair(intervals[i][0],i));
        }
        for(int i=0;i<sz;i++)
        {
            auto it = myM.lower_bound(intervals[i][1]);
            if(it!=myM.end())
            {
                result.push_back(it->second);
            }
            else result.push_back(-1);
        }
        return result;
    }
};