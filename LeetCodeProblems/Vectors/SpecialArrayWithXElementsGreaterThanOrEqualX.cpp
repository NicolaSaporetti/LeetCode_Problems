#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sz = nums.size();
        for(int i=0;i<=nums.size();i++)
        {
            int index = sz-(lower_bound(nums.begin(),nums.end(),i)-nums.begin());
            if(index<i)
            {
                return -1;
            }
            if(index==i) return i;
        }
        return -1;
    }
};