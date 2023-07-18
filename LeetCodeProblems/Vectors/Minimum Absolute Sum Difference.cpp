#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long res=0;
        int mod = 1e9+7;
        long long maxd = 0;
        int sz = nums1.size();
        set<int> s;
        for(auto& e : nums1) s.insert(e);
        for(int i=0;i<sz;i++)
        {
            long long dif=abs(nums1[i]-nums2[i]);
            res+=dif;
            auto it = s.lower_bound(nums2[i]);
            long long newd = INT_MAX;
            if(it!=s.end()) newd = abs(*it-nums2[i]);
            if(it!=s.begin()) newd = min(newd,(long long)abs(*prev(it)-nums2[i]));
            maxd = max(maxd, dif-newd);
        }
        return (res-maxd)%mod;
    }
};