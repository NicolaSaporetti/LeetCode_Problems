#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        map<int,int> m;
        int res = INT_MAX;
        int sz = nums.size();
        for(int i=x;i<sz;i++) m[nums[i]]++;
        for(int i=0;i<sz;i++)
        {
            auto it = m.lower_bound(nums[i]);
            if(it!=m.end()) res = min(res,abs(it->first-nums[i]));
            if(it!=m.begin()) res = min(res,abs(prev(it)->first-nums[i]));
            if(i+x<sz)
            {
                int val = nums[i+x];
                m[val]--;
                if(m[val]==0) m.erase(val);
            }
            if(i-x+1>=0 && i-x+1<sz)
            {
                int val = nums[i-x+1];
                m[val]++;
            }
        }
        return res;
    }
};