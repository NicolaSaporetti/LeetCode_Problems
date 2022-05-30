#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int skipped_elements = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
            {
                skipped_elements++;
            }
            else
            {
                nums[i-skipped_elements] = nums[i];
            }
        }
        return nums.size()-skipped_elements;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1,1,1,2,2,2,2,3,3};
    cout<<"Size: "<<solution.removeDuplicates(nums)<<endl;
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<endl;
    }
    return 0;
}