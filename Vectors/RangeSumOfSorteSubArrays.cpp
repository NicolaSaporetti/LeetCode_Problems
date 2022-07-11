#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> values((n*(n+1))/2, 0);
        int mod = 1000000007;
        int ind = 0;
        int result = 0;
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++)
            {
                sum+= nums[j];
                sum%=mod;
                values[ind++] =sum;
            }
        }
        sort(values.begin(),values.end());
        for(int i = left-1;i<right;i++)
        {
            result+=values[i];
            result%=mod;
        }
        return result;
    }
};