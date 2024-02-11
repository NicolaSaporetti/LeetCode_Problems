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
        for(int i=0;i<sz;i++)
        {
            if(nums[i]<0) continue;
            long long v = nums[i]-i;
            m[v]+=nums[i];
            auto it = m.find(v);
            if(it!=m.begin()) it->second = max(it->second, prev(it)->second+nums[i]);
            while(next(it)!=m.end() && next(it)->second<=it->second) m.erase(next(it));
        }
        return m.rbegin()->second;
    }
};