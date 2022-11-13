#include <set>
using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long tot = ((long long)k*((long long)k+1))/2;
        set<int> s;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        for(auto e : s)
        {
            if(e<=k)
            {
                tot-=e;
                k++;
                tot+=k;
            }
            else break;
        }
        return tot;
    }
};