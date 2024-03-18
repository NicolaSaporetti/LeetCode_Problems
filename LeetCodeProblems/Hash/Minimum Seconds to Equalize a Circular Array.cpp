#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int n = nums.size();
        int r = INT_MAX;
        for(int i=0;i<n;i++) m[nums[i]].push_back(i);
        for(auto [k,v] : m)
        {
            int t = 0;
            for(int i=0;i<v.size();i++)
            {
                int i1 = v[i];
                int i2 = v[(i+1)%v.size()];
                if(i1<i2) t = max((i2-i1)/2,t);
                else t = max((n-i1+i2)/2,t);
            }
            r = min(r,t);
        }
        return r;
    }
};