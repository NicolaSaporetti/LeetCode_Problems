#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> o;
        for(auto& e : nums) o.insert(e);
        int res = 0;
        int sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            set<int> s;
            for(int j=i;j<sz;j++)
            {
                s.insert(nums[j]);
                if(s.size()==o.size()) res++;
            }
        }
        return res;
    }
};