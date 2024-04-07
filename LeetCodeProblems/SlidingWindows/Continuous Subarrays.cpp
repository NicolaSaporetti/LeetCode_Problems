#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int> m;
        int s = 0;
        long long res = 0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            while(m.rbegin()->first-m.begin()->first>2)
            {
                m[nums[s]]--;
                if(m[nums[s]]==0) m.erase(nums[s]);
                s++;
            }
            res+=(long long)(i-s+1);
        }
        return res;
    }
};