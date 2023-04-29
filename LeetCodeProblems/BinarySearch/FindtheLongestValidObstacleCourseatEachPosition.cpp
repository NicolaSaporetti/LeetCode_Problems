#include <vector>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int sz = obstacles.size();
        vector<int> res;
        vector<int> lrs;
        for(int i=0;i<sz;i++)
        {
            auto it = upper_bound(begin(lrs),end(lrs),obstacles[i]);
            if(it==end(lrs))
            {
                lrs.push_back(obstacles[i]);
                res.push_back(lrs.size());
            }
            else
            {
                *it = obstacles[i];
                res.push_back(it-begin(lrs)+1);
            }
        }
        return res;
    }
};