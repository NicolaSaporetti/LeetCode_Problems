#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0) return 0;
        coinsByAmount.assign(amount+1,0);
        sort(coins.begin(),coins.end());
        remove_coins_value_too_high(coins, amount);
        if(coins.empty()) return -1;
        compute_min_coin_amount(coins);
        if (coinsByAmount[amount]<20000) return coinsByAmount[amount];
        else return -1;
    }
    
private:
    
    void remove_coins_value_too_high(vector<int>& coins, int amount)
    {
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]>amount)
            {
                coins.resize(i);
                break;
            }
        }
    }
    
    void compute_min_coin_amount(vector<int>& coins)
    {
        for(int i=1;i<coinsByAmount.size();i++)
        {
            int tempMin = 20000;
            for(int j=0;j<coins.size();j++)
            {
                int remaining = i-coins[j];
                if(remaining>=0) tempMin = min(tempMin,1+coinsByAmount[remaining]);
            }
            if(tempMin != INT_MAX) coinsByAmount[i] = tempMin;
            else coinsByAmount[i] = 20000;
            
        }
    }
    
    vector<int> coinsByAmount;
};