#include <vector>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp(3);
        for(auto a:nums){
            for(int i:vector<int>(dp)){
                dp[(i+a)%3]=max(dp[(i+a)%3],i+a);
            }
        }
       return dp[0];
    }
};