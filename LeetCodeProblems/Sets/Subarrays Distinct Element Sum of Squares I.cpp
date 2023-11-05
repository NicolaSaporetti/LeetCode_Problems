#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sz = nums.size();
        int res = 0;
        for(int i=0;i<sz;i++)
        {
            set<int> m;
            for(int j=i;j<sz;j++)
            {
                m.insert(nums[j]);
                res+=(m.size()*m.size());
            }
        }
        return res;
    }
};