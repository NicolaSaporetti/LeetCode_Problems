#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int,int> m;
        for(int i=1;i<nums.size();i++)
        {
            m[nums[i]+nums[i-1]]++;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second>=2) return true;
        }
        return false;
    }
};