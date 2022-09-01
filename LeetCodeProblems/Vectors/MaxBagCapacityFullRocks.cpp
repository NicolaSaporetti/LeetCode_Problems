#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int sz = rocks.size();
        int total = 0;
        for(int i=0;i<sz;i++)
        {
            capacity[i]-=rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        for(int i=0;i<sz;i++)
        {
            if(capacity[i]<=additionalRocks)
            {
                additionalRocks-=capacity[i];
                total++;
            }
            else break;
        }
        return total;
    }
};