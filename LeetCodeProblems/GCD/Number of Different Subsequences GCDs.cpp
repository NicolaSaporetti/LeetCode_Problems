#include <vector>
using namespace std;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums)
    {
        int max_num = *max_element(begin(nums), end(nums))
        int res = 0;
        vector<bool> flags(max_num + 1);
        for (auto num : nums) flags[num] = true;
        for (auto i = 1; i <= max_num; ++i) {
            int ni_gcd = flags[i] ? i : 0;
            for (auto n = 1; n * i <= max_num && ni_gcd != i; ++n)
                if (flags[n * i])
                    ni_gcd = ni_gcd ? gcd(ni_gcd, n * i) : n * i;
            res += ni_gcd == i;
        }
        return res;
    }
};