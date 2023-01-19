#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> v(k,0);
        int temp = 0;
        int res = 0;
        v[0]++;
        for(auto& e : nums)
        {
            temp+=e;
            if(v[(temp%k+k)%k]!=0) res+=v[(temp%k+k)%k];
            v[(temp%k+k)%k]++;
        }
        return res;
    }
};