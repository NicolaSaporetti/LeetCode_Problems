#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    set<int> myS;
    int sz;
    void fillSet(vector<int>& nums)
    {
        for(int i=0;i<sz;i++)
        {
            myS.insert(nums[i]);
        }
    }
    
    int computeLongestSequence()
    {
        int result = 0;
        auto it = myS.begin();
        int temp = 1;
        int first = *it;
        it++;
        for(;it!=myS.end();it++)
        {
            int second = *it;
            if(second == first+1)
            {
                temp++;
            }
            else
            {
                result = max(result,temp);
                temp = 1;
            }
            first = second;
        }
        return max(result,temp);
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        sz = nums.size();
        if(sz<=1) return sz;
        else
        {
            fillSet(nums);
            return computeLongestSequence();
        }
    }
};