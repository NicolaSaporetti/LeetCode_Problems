#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(),inventory.end());
        int mod = 1000000007;
        int maxN = inventory[inventory.size()-1];
        long long result = 0;
        int high = min(orders,maxN);
        int low = 0;
        while(low<high)
        {
            long long total = 0;
            int mid=low+(high-low+1)/2;
            for(int i=inventory.size()-1;i>=0;i--)
            {
                total+=max(inventory[i]+mid-maxN,0);
            }
            if(total>orders) high = mid-1;
            else low = mid;
        }
        int total = 0;
        for(int i=inventory.size()-1;i>=0;i--)
        {
            if(inventory[i]+low>maxN)
            {
                long long number = inventory[i];
                result+=((number+1)*number)/2;
                number = maxN-low;
                result-=((number+1)*number)/2;
                result%=mod;
                total+=inventory[i]+low-maxN;
            }
        }
        result+=(long long)(orders-total)*(long long)(maxN-low);
        result%=mod;
        return result;
    }
};