#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,long long> m;
        long long res = 0;
        long long tot = 0;
        int sz = nums.size();
        int start = 0;
        for(int i=0;i<sz;i++)
        {
            long long prev_sum = (m[nums[i]]*(m[nums[i]]-1))/2;
            m[nums[i]]++;
            long long new_sum = (m[nums[i]]*(m[nums[i]]-1))/2;
            res+=(new_sum-prev_sum);
            if(res>=k)
            {
                tot+=(sz-i);
                do
                {
                    long long ps = (m[nums[start]]*(m[nums[start]]-1))/2;
                    m[nums[start]]--;
                    long long ns = (m[nums[start]]*(m[nums[start]]-1))/2;
                    res+=(ns-ps);
                    start++;
                    if(res>=k) tot+=(sz-i);
                } while(res>=k);
            }
        }
        return tot;
    }
};