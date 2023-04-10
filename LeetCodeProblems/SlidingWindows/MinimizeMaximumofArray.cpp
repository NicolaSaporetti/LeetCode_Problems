#include <vector>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long tot= 0;
        int sz = nums.size();
        for(auto& e : nums) tot+=(long long)(e);
        int ws = 0;
        long long temp = 0;
        for(int i=sz-1;i>=0;i--)
        {
            ws++;
            temp+=(long long)nums[i];
            if(temp/ws<(tot/(i+ws)))
            {
                tot-=temp;
                ws=0;
                temp = 0;
            }
        }
        return temp/ws+((temp%ws!=0)? 1 : 0);
    }
};