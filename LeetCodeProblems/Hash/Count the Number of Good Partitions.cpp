#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        map<int,vector<int>> m;
        vector<int> v(nums.size(),0);
        for(int i=0;i<nums.size();i++) m[nums[i]].push_back(i);
        for(auto& [k,va] : m)
            if(va.size()>=2)
            {
                v[va[0]]++;
                v[va.back()]--;
            }
        for(int i=1;i<nums.size();i++) v[i]+=v[i-1];
        int part =0;
        for(int i=0;i<nums.size();i++) if(v[i]==0) part++;
        int res = 1;
        int mod = 1e9+7;
        for(int i=0;i<part-1;i++) res = (res*2)%mod;
        return res;
    }
};