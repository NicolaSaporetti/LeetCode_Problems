#include <vector>
using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int acc = 0;
        int res = 0;
        sort(begin(coins),end(coins));
        for(int i=0;i<coins.size();)
        {
            if(acc>=target) return res;
            if(acc+1>=coins[i]) acc+=coins[i++];
            else
            {
                acc+=(acc+1);
                res++;
            }
        }
        while(acc<target)
        {
            acc+=(acc+1);
            res++;
        }
        return res;
    }
};