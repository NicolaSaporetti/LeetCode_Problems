#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = -1;
        for(int i=0;i<accounts.size();i++)
        {
            int sum = 0;
            for(int j=0;j<accounts[0].size();j++)
            {
                sum+=accounts[i][j];
            }
            maxWealth = max(maxWealth,sum);
        }
        return maxWealth;
    }
};