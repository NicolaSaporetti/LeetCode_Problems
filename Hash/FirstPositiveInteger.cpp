#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    set<int> Myset;
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<=nums.size();i++)
        {
            Myset.insert(i+1);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) Myset.erase(nums[i]);
        }
        return *(Myset.begin());     
    }
};

int main()
{
    vector<int> nums = {1,2,4};
    Solution sol;
    cout<<sol.firstMissingPositive(nums)<<endl;
}