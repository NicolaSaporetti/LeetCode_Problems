#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];

        for (const int price : prices) {
          cash = max(cash, hold + price - fee);
          hold = max(hold, cash - price);
        }

        return cash;
    }
};