#include <vector>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector <int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int d = INT_MAX;
        bool c = false;
        for (int a : nums) {
            int b = a ^ k;
            res += max(a, b);
            if(a<b) c=!c;
            d = min(d, abs(a - b));
        }
        return res - d * c;
    }
};