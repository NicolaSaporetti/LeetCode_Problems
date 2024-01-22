#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,set<int>> m;
        int res = 0;
        int s = 0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].insert(i);
            if(m[nums[i]].size()>k)
            {
                int el = *m[nums[i]].begin();
                m[nums[i]].erase(el);
                while(s<=el)
                {
                    m[nums[s]].erase(s);
                    s++;
                }
            }
            res = max(res,i-s+1);
        }
        return res;
    }
};