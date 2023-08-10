#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,vector<int>> m;
        int res = INT_MAX;
        int osz = nums.size();
        for(int i=0;i<nums.size();i++) m[nums[i]].push_back(i);
        for(auto& [k,v] : m)
        {
            int d = 0;
            int sz = v.size();
            if(sz==1) d = osz/2;
            else
            {
                for(int i=0;i<sz-1;i++) d = max(d,(v[i+1]-v[i])/2);
                d = max(d,(v[0]+osz-v.back())/2);
            }
            res = min(res,d);
        }
        return res;
    }
};