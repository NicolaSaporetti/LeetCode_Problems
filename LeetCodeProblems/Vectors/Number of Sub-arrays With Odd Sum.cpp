#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> v(2,0);
        v[0]=1;
        int val = 0;
        int r = 0;
        int mod = 1e9+7;
        for(auto e : arr)
        {
            val+=e;
            r=(r+v[1-val%2])%mod;
            v[val%2]++;
        }
        return r;
    }
};