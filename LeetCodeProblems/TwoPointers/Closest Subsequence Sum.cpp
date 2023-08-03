#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        sz = nums.size();
        set<int> s1 = compute(nums,0,sz/2);
        set<int> s2 = compute(nums,sz/2,sz);
        int res = INT_MAX;
        for(auto& e : s1)
        {
            int v =e-goal;
            auto it = s2.lower_bound(-v);
            if(it!=s2.end()) res = min(res,abs(v+*it));
            if(it!=s2.begin()) res = min(res,abs(v+*prev(it)));
        }
        return res;
    }
private:
    set<int> compute(vector<int>& nums, int start, int end)
    {
        set<int> s;
        for(int i=0;i<(1<<(end-start));i++)
        {
            int val = 0;
            for(int j=0;j<end-start+1;j++)
            {
                if((1<<j)&i) val+=nums[j+start];
            }
            s.insert(val);
        }
        return s;
    }
    
    int sz;
};