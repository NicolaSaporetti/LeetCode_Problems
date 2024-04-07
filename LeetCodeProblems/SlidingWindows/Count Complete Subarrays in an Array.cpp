#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int sz = nums.size();
        int res = 0;
        int distinct = 0;
        unordered_set<int> s0;
        for(auto e : nums) s0.insert(e);
        distinct = s0.size();
        unordered_map<int,int> m;
        int start = 0;
        for(int i=0;i<sz;i++)
        {
            m[nums[i]]++;
            if(m.size()==distinct)
            {
                while(m[nums[start]]>1)
                {
                    m[nums[start++]]--;
                }
                res+=(start+1);
            }
        }
        return res;
    }
};