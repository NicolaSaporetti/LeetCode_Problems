#include <vector>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int res = 0;
        int totd = 0;
        for(auto e : nums)
        {
            res+=e;
            while(e>0)
            {
                totd+=(e%10);
                e/=10;
            }
        }
        return res-totd;
    }
};