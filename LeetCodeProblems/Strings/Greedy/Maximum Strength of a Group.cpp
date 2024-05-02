#include <vector>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int sz = nums.size();
        long long r = 1;
        vector<long long> ve;
        for(auto e : nums)
        {
            if(e>0) r*=(long long)e;
            else if(e<0) ve.push_back(e);
        }
        if(r==1 && ve.size()<=1) return *max_element(begin(nums),end(nums));
        for(int i=0;i<ve.size()/2;i++)
        {
            r*=ve[i*2];
            r*=ve[i*2+1];
        }
        return r;
    }
};