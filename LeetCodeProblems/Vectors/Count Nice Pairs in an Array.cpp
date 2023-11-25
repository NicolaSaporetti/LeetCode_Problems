#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int mod = 1e9+7;
        int res = 0;
        for(auto e : nums)
        {
            int n = e;
            int ne = 0;
            while(n>0)
            {
                ne*=10;
                ne+=n%10;
                n/=10;
            }
            e-=ne;
            res=(res+m[e])%mod;
            m[e]++;
        }
        return res;
    }
};