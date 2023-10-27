#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> v(1,0);
        int sz = nums.size();
        int res = INT_MIN;
        for(int i=0;i<sz;i++)
        {
            if(i>=k)
            {
                int e = v[i-k];
                m[e]--;
                if(m[e]==0) m.erase(e);
            }
            int el = nums[i]+ ((m.empty())? 0 : m.rbegin()->first);
            if(el>=0) m[el]++;
            res = max(res,el);
            v.push_back(el);
        }
        return res;
    }
};