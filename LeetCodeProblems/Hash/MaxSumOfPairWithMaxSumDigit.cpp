#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int total = -1;
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++)
        {
            int temp = nums[i];
            int res = 0;
            while(temp>0)
            {
                res+=temp%10;
                temp/=10;
            }
            m[res].push_back(nums[i]);
        }
        for(auto it = m.begin();it!=m.end();it++)
        {
            int sz = it->second.size();
            if(sz>=2)
            {
                sort(it->second.begin(),it->second.end());
                total = max(total, it->second[sz-1]+it->second[sz-2]);
            }
        }
        return total;
    }
};