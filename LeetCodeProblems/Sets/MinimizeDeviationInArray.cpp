#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        int res = INT_MAX;
        for(auto e : nums) s.insert(e);
        for(auto it = s.begin();it!=s.end();)
        {
            if(*it%2==1)
            {
                s.insert(*it*2);
                s.erase(it++);
            }
            else it++;
        }
        res = min(res, *s.rbegin()-*s.begin());
        for(auto it=s.rbegin();it!=s.rend();)
        {
            if(*it%2==1) break;
            s.insert(*it/2);
            s.erase(next(it++).base());
            res = min(res, *s.rbegin()-*s.begin());
        }
        return res;
    }
};