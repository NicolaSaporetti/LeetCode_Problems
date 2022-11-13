#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<long long> coinsByAmount;
    
    void compute_comb(vector<int>& coins)
    {
        coinsByAmount[0] = 1;
        for(int i=0;i<coinsByAmount.size();i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i+coins[j]<coinsByAmount.size())
                {
                    coinsByAmount[i+coins[j]]+=coinsByAmount[i];
                    coinsByAmount[i+coins[j]]%=INT_MAX;
                }
            }
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target ==0) return 0;
        coinsByAmount.resize(target+1);
        sort(nums.begin(),nums.end());
        compute_comb(nums);
        return coinsByAmount[target];
    }
};