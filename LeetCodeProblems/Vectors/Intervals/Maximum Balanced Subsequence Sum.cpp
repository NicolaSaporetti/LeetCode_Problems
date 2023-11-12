#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        if(all_of(begin(nums),end(nums),[](int elem){return elem<0;})) return *max_element(begin(nums),end(nums));
        int sz=nums.size();
        long long res=0;
        map<long long, long long> m;
        m[INT_MIN]=0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]<=0) continue;
            long long val = nums[i]-i;
            auto it = prev(m.upper_bound(val));
            m[val]=it->second+nums[i];
            it = m.find(val);
            if(prev(it)->second>it->second) m.erase(it);
            else while(next(it)!=m.end() && next(it)->second<=it->second) m.erase(next(it));
        }
        return m.rbegin()->second;
    }
};