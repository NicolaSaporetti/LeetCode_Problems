#include <vector>
using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> v;
        for(auto& e : nums) v.push_back(e);
        int sz = nums.size();
        long long res = 0;
        for(int i=sz-1;i>=1;i--)
        {
            if(v[i]>=v[i-1]) v[i-1]+=v[i];
        }
        return v[0];
    }
};