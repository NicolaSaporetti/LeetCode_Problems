#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        map<long long,long long> m;
        long long res = 0;
        int mod = 1e9+7;
        for(auto& e : nums)
        {
            long long prev = e;
            long long old = e;
            long long newN = 0;
            while(old>0)
            {
                newN*=10;
                newN+=old%10;
                old/=10;
            }
            m[prev-newN]++;
        }
        for(auto& [k,v] : m)
        {
            res+=(v*(v-1))/2;
        }
        return res%mod;
    }
};