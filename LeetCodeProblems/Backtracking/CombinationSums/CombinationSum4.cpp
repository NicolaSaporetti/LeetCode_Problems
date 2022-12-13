#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        coinsByAmount.assign(target+1,0);
        compute_comb(nums,target+1);
        return coinsByAmount[target];
    }
private:
    void compute_comb(vector<int>& coins, int target)
    {
        coinsByAmount[0] = 1;
        int sz = coins.size();
        for(int i=1;i<target;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(i-coins[j]>=0) coinsByAmount[i]= (coinsByAmount[i]+coinsByAmount[i-coins[j]])%INT_MAX;
            }
        }
    }

    vector<long long> coinsByAmount;
};