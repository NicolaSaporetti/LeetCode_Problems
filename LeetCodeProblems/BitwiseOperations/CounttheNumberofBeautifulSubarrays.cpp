#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        map<int,int> m;
        m[0]++;
        int val = 0;
        long long res = 0;
        for(int i=0;i<nums.size();i++)
        {
            val^=nums[i];
            res+=(long long)m[val];
            m[val]++;
        }
        return res;
    }
};