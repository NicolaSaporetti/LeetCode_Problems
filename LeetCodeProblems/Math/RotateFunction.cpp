#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        map<long long,pair<long long,long long>> m;
        long long tot = 0;
        long long res = INT_MIN;
        int sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            m[nums[i]].second+=i;
            m[nums[i]].first++;
            tot+=(nums[i]*i);
        }
        res = max(res,tot);
        for(int i=1;i<sz;i++)
        {
            tot = 0;
            m[nums[i-1]].second+=sz;
            for(auto& e : m)
            {
                e.second.second-=e.second.first;
                tot+=(e.first*e.second.second);
            }
            res = max(res,tot);
        }
        return res;
    }
};